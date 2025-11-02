#pragma once

#include <string>
#include <filesystem>
#include <utility>
#include <verilated_vcd_c.h>
#include "verilated.h"
#include "ITest.h"

template<typename TDut>
class TestBase : public ITest {
protected:
    std::string testName;
    std::unique_ptr<TDut> dut;
    std::unique_ptr<VerilatedVcdC> vcd;

public:
    explicit TestBase(std::string testName) : testName(std::move(testName)), dut(std::make_unique<TDut>()),
                                              vcd(std::make_unique<VerilatedVcdC>()) {}

    void setUp() override {
        namespace fs = std::filesystem;

        Verilated::traceEverOn(true);

        dut->trace(vcd.get(), 99);

        if (!fs::exists("obj_dir/waves/")) {
            fs::create_directories("obj_dir/waves/");
        }

        std::string fileName = "obj_dir/waves/" + this->testName + ".vcd";

        vcd->open(fileName.c_str());
    }

    void tearDown() override {
        dut->final();
    }
};