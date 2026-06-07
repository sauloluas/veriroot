#pragma once

#include "VTop.h"
#include "runner/TestBase.h"
#include "runner/TestRegister.h"

class SystemTB : public TestBase<VTop>
{
public:
    SystemTB() : TestBase("system")
    {
        addTest("system", [this] { test_system(); });
    }

    void test_system() const
    {
        dut->clk = 0;

        for (int i = 0; i < 30; i++)
        {
            dut->clk = !dut->clk;
            dut->eval();
            vcd->dump(Verilated::time());
            Verilated::timeInc(1);
        }
    }
};

REGISTER_TEST("system", SystemTB)
