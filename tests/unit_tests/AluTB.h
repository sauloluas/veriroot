#pragma once

#include "VAlu.h"
#include "runner/TestBase.h"
#include "runner/TestRegister.h"

#define DONT_CARE8 (uint8_t)0b00000000

enum AluCmd : uint8_t
{
    DC = 0b11,
    ADD = 0b00,
    NAND = 0b01,
    SHFT = 0b10,
};

typedef struct Immed
{
    uint8_t flag : 1;
    uint8_t shamt : 3;

    [[nodiscard]] uint8_t to_bits() const
    {
        return static_cast<uint8_t>(((flag << 3) | shamt) & 0x0F);
    }
} Immed;

class AluTB : public TestBase<VAlu>
{
public:
    AluTB() : TestBase("alu")
    {
        addTest("add", [this] { test_add(); });
        addTest("nand", [this] { test_nand(); });
        addTest("shift_left", [this] { test_shift_left(); });
        addTest("shift_right", [this] { test_shift_right(); });
        addTest("mult", [this] { test_mult(); });
    }

private:
    void test_add() const
    {
        dut->a = 6;
        dut->b = 4;
        dut->cmd = ADD;

        eval();
        CHECK(dut->x == 10);
    }

    void test_nand() const
    {
        dut->a = 0b00000101;
        dut->b = 0b00000011;
        dut->cmd = NAND;

        eval();
        CHECK(dut->x == 0b11111110);
    }

    void test_shift_left() const
    {
        constexpr Immed n{.flag = 0b0, .shamt = 0b010};

        dut->a = 0b00000010;
        dut->b = DONT_CARE8;
        dut->cmd = SHFT;

        dut->n = n.to_bits();
        eval();

        CHECK(dut->x == 0b00001000);
    }

    void test_shift_right() const
    {
        constexpr Immed n{.flag = 0b1, .shamt = 0b010};

        dut->a = 0b00001000;
        dut->b = DONT_CARE8;
        dut->cmd = SHFT;

        dut->n = n.to_bits();
        eval();

        CHECK(dut->x == 0b00000010);
    }

    void test_mult() const
    {
        uint8_t a = 0b00000110;
        uint8_t b = 0b00000101;

        uint8_t result = 0;

        while (b != 0)
        {
            if (b & 1)
            {
                // result += a;
                dut->a = result;
                dut->b = a;

                dut->cmd = ADD;

                eval();

                result = dut->x;
            }

            /// a <<= 1
            dut->a = a;

            Immed n{.flag = 0b0, .shamt = 0b01};

            dut->cmd = SHFT;
            dut->n = n.to_bits();

            eval();

            a = dut->x;

            /// b >>= 1
            dut->a = b;

            n = {.flag = 0b1, .shamt = 0b01};

            dut->cmd = SHFT;
            dut->n = n.to_bits();

            eval();

            b = dut->x;
        }

        std::printf("%dcycles\n", this->clocks_count());

        CHECK(result == 0b00011110);
    }
};

REGISTER_TEST("alu", AluTB)
