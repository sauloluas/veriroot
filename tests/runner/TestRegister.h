#pragma once

#include "TestRegistry.h"

#define REGISTER_TEST(NAME, TYPE)                   \
    namespace {                                     \
        const bool registered_##TYPE = [] {         \
            TestRegistry::registerTest(NAME, [] {   \
                return std::make_unique<TYPE>();    \
            });                                     \
                                                    \
            return true;                            \
        }();                                        \
    }
