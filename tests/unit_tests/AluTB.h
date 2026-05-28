#pragma once

#include "VTop.h"
#include "runner/TestBase.h"
#include "runner/TestRegister.h"

#include <random>

class AluTB : public TestBase<VTop>
{
public:
    AluTB() : TestBase("alu")
    {
    }

    void run() override
    {
        dut->clk = 0;

        for (int i = 0; i < 30; i++)
        {
            std::random_device rd;

            std::mt19937 gen(rd());

            std::uniform_real_distribution distr(0.0, 1.0);

            if (distr(gen) > 0.5)
            {
                dut->clk = !dut->clk;
            }

            dut->eval();
            vcd->dump(Verilated::time());
            Verilated::timeInc(1);
        }
    }
};

REGISTER_TEST("alu", AluTB)
