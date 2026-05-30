#pragma once

#include "VAlu.h"
#include "runner/TestBase.h"
#include "runner/TestRegister.h"

#include <random>

#define ALU_N(flag, shamt) (((flag << 3) | shamt) & 0x0F)
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
    }

    void run() override
    {
        this->add();
        this->step();

        this->nand();
        this->step();

        this->shift_left();
        this->step();

        this->shift_right();
        this->step();
    }

    void add() const
    {
        dut->a = 6;
        dut->b = 4;
        dut->cmd = ADD;

        dut->eval();

        assert(dut->x == 10);
    }

    void nand() const
    {
        dut->a = 0b00000101;
        dut->b = 0b00000011;
        dut->cmd = NAND;

        dut->eval();

        assert(dut->x == 0b11111110);
    }

    void shift_left() const
    {
        dut->a = 0b00000010;
        dut->b = DONT_CARE8;
        dut->cmd = SHFT;

        constexpr Immed n{
            .flag = 0b0, // false
            .shamt = 0b010,
        };

        dut->n = n.to_bits();

        assert(dut->n == 0b0010);

        dut->eval();

        assert(dut->x == 0b00001000);
    }

    void shift_right() const
    {
        dut->a = 0b00001000;
        dut->b = DONT_CARE8;
        dut->cmd = SHFT;

        constexpr Immed n{
            .flag = 0b1, // true
            .shamt = 0b010,
        };

        dut->n = n.to_bits();

        assert(dut->n == 0b1010);

        dut->eval();

        assert(dut->x == 0b00000010);
    }
};

REGISTER_TEST("alu", AluTB)
