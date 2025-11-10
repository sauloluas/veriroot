#pragma once

#include <functional>
#include <memory>
#include <iostream>

#include "TestBase.h"

class TestRegistry {
public:
    using FactoryFn = std::function<std::unique_ptr<ITest>()>;

    static std::map<std::string, FactoryFn> &registry() {
        static std::map<std::string, FactoryFn> registry;
        return registry;
    }

    static void registerTest(const std::string& name, FactoryFn fn) {
        registry()[name] = std::move(fn);
    }

    static std::unique_ptr<ITest> create(std::string& name) {
        auto it = registry().find(name);

        if (it == registry().end()) {
            std::cerr << "Test not found: " << name << std::endl;
            return nullptr;
        }

        return it->second();
    }
};