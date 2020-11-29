#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "memory.h"
#include "instruction.h"

namespace Func
{
    void JAL  (Memory* mem, Instruction* insn);
    void AUIPC(Memory* mem, Instruction* insn);
    void ADDI (Memory* mem, Instruction* insn);
    void ANDI (Memory* mem, Instruction* insn);
    void JALR (Memory* mem, Instruction* insn);
    void LW   (Memory* mem, Instruction* insn);
    void SUB  (Memory* mem, Instruction* insn);
}

#endif //FUNCTIONS_H