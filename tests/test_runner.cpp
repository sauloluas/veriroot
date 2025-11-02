#include <iostream>

#include "runner/TestRegistry.h"

#include "SystemTB.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <test_name>\n";
        return 1;
    }

    std::string testName = argv[1];

    std::unique_ptr<ITest> tb = TestRegistry::create(testName);

    if (!tb) {
        std::cout << "Test not found";
        return 1;
    }

    tb->setUp();
    tb->run();
    tb->tearDown();

    return 0;
}
