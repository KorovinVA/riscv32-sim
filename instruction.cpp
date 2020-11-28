#include "instruction.h"

Instruction::Instruction(uint32_t raw) :
    name()
{
    data = raw;

    if(getBits(data, 6, 0) == 0x6f)
    {
        opcode = OP::JAL;
        type   = TYPE::J;

        rd     = getBits(data, 11, 7);

        uint32_t imm0_10  = getBits(data, 30, 21) << 1;
        uint32_t imm11_11 = getBits(data, 20, 20);
        uint32_t imm19_12 = getBits(data, 19, 12);
        uint32_t imm20_20 = getBits(data, 19, 12);

        imm = imm0_10 + (imm11_11 << 11) + (imm19_12 << 12) + (imm20_20 << 20);
    }
    else
    {
        throw std::string("Unkown Instruction: " + std::to_string(data));
    }


}

uint32_t Instruction::operator() (const uint32_t end, const uint32_t start)
{
    return getBits(data, end, start);
}


uint32_t Instruction::getBits(uint32_t raw, uint32_t end, uint32_t start)
{
    raw = raw << (31 - end);
    raw = raw >> (31 - end);
    raw = raw >> start;
    return raw;
}

Instruction::~Instruction()
{}