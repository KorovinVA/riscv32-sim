#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <iostream>

enum class OP
{
    JAL,
    INVALID
};

enum class TYPE
{
    R,
    I,
    S,
    B,
    U,
    J,
    INVALID
};

class Instruction
{
public:
    Instruction(uint32_t raw);
    ~Instruction();
    uint32_t operator() (const uint32_t end, const uint32_t start);
private:
    uint32_t getBits(uint32_t raw, uint32_t end, uint32_t start);

    OP opcode;
    TYPE type;

    uint32_t data;
    uint32_t rd  = 0;
    uint32_t rs1 = 0;
    uint32_t rs2 = 0;
    uint32_t imm = 0;

    std::string name;
};

#endif //INSTRUCTION_H