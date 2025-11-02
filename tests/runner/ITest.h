#pragma once

class ITest {
public:
    virtual ~ITest() = default;

    virtual void setUp() = 0;
    virtual void run() = 0;
    virtual void tearDown() = 0;
};