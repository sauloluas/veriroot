#include <iostream>

#include "runner/TestRegistry.h"

#include "SystemTB.h"
#include "AluTB.h"

static int runTest(const std::string& testName)
{
    const std::unique_ptr<ITest> tb = TestRegistry::create(testName);

    if (!tb)
    {
        std::cout << "Test not found: " << testName << "\n";
        return 1;
    }

    tb->setUp();

    try
    {
        tb->run();
    }
    catch (...)
    {
        tb->tearDown();
        return 1;
    }

    tb->tearDown();

    return 0;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        int exitCode = 0;

        for (auto& [name, _] : TestRegistry::registry())
        {
            exitCode |= runTest(name);
        }

        return exitCode;
    }

    return runTest(argv[1]);
}
