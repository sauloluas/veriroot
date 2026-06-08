#pragma once

#include <string>
#include <vector>
#include <functional>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <verilated_vcd_c.h>
#include "verilated.h"
#include "ITest.h"

#define CHECK(cond) \
    do { if (!(cond)) throw std::runtime_error("CHECK failed: " #cond); } while (0)

template <typename TDut>
class TestBase : public ITest
{
    struct TestCase
    {
        std::string name;
        std::function<void()> fn;
    };

    struct TestResult
    {
        std::string name;
        bool passed;
        std::string message;
        std::string output;
    };

    std::vector<TestCase> testCases;
    mutable uint64_t simTime = 0;
    mutable int clocks_count_ = 0;

protected:
    std::string testName;
    std::unique_ptr<TDut> dut;
    std::unique_ptr<VerilatedVcdC> vcd;

public:
    explicit TestBase(std::string testName) : testName(std::move(testName))
    {
    }

    void setUp() override
    {
        namespace fs = std::filesystem;

        Verilated::traceEverOn(true);

        for (const std::string sub : {"all", "pass", "fail"})
        {
            fs::create_directories("obj_dir/waves/" + sub);
        }

        fs::create_directories("test-results");
    }

    void run() override
    {
        namespace fs = std::filesystem;

        bool anyFailed = false;
        std::vector<TestResult> results;

        std::cout << ":::::::: " << testName << " ::::::::\n";

        for (auto& tc : testCases)
        {
            std::cout << "running `" << tc.name << "`\n";

            std::string filename = testName + "_" + tc.name + ".vcd";
            std::string allPath = "obj_dir/waves/all/" + filename;

            fs::remove(allPath);
            fs::remove("obj_dir/waves/pass/" + filename);
            fs::remove("obj_dir/waves/fail/" + filename);

            resetDut();

            vcd->open(allPath.c_str());

            std::ostringstream captured;
            std::streambuf* realCout = std::cout.rdbuf(captured.rdbuf());

            try
            {
                tc.fn();

                this->dump();
                vcd->close();

                std::cout.rdbuf(realCout);
                std::string output = captured.str();

                if (!output.empty())
                {
                    std::cout << output;
                }

                fs::create_symlink("../all/" + filename, "obj_dir/waves/pass/" + filename);
                std::cout << "[PASS] " << tc.name << "\n\n";

                results.push_back({tc.name, true, "", output});
            }
            catch (const std::exception& e)
            {
                this->dump();
                vcd->close();

                std::cout.rdbuf(realCout);
                std::string output = captured.str();

                if (!output.empty())
                {
                    std::cout << output;
                }

                fs::create_symlink("../all/" + filename, "obj_dir/waves/fail/" + filename);
                std::cerr << "[FAIL] " << tc.name << ": " << e.what() << "\n\n";

                results.push_back({tc.name, false, e.what(), output});

                anyFailed = true;
            }
        }

        writeJUnitXml(results);

        if (anyFailed)
        {
            throw std::runtime_error("one or more tests failed");
        }
    }

    void tearDown() override
    {
        if (dut) dut->final();
    }

protected:
    void addTest(const std::string& name, std::function<void()> fn)
    {
        testCases.push_back({name, std::move(fn)});
    }

    void eval() const
    {
        dut->eval();
        this->dump();

        simTime++;
        clocks_count_++;
    }

    const int& clocks_count() const
    {
        return clocks_count_;
    }


private:
    void resetDut()
    {
        simTime = 0;

        if (dut) dut->final();

        dut = std::make_unique<TDut>();
        vcd = std::make_unique<VerilatedVcdC>();

        dut->trace(vcd.get(), 99);
    }

    void dump() const
    {
        vcd->dump(simTime);
    }

    void writeJUnitXml(const std::vector<TestResult>& results) const
    {
        int failures = 0;
        for (const auto& r : results)
            if (!r.passed) failures++;

        std::ofstream f("test-results/" + testName + ".xml");

        f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        f << "<testsuite name=\"" << testName << "\""
            << " tests=\"" << results.size() << "\""
            << " failures=\"" << failures << "\""
            << " errors=\"0\">\n";

        for (const auto& r : results)
        {
            f << "    <testcase name=\"" << r.name << "\""
                << " classname=\"" << testName << "\"";

            const bool hasContent = !r.passed || !r.output.empty();

            if (!hasContent)
            {
                f << "/>\n";
            }
            else
            {
                f << ">\n";

                if (!r.passed)
                {
                    f << "        <failure message=\"" << r.message << "\">"
                        << r.message << "</failure>\n";
                }

                if (!r.output.empty())
                {
                    f << "        <system-out><![CDATA[" << r.output << "]]></system-out>\n";
                    f << "    </testcase>\n";
                }
            }
        }

        f << "</testsuite>\n";
    }
};
