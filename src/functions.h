#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "instruction.h"
#include "memory.h"

namespace Func {
void LUI(Memory* mem, Instruction* insn);
void JAL(Memory* mem, Instruction* insn);
void JALR(Memory* mem, Instruction* insn);
void AUIPC(Memory* mem, Instruction* insn);

void BEQ(Memory* mem, Instruction* insn);
void BNE(Memory* mem, Instruction* insn);
void BLT(Memory* mem, Instruction* insn);
void BGE(Memory* mem, Instruction* insn);
void BLTU(Memory* mem, Instruction* insn);
void BGEU(Memory* mem, Instruction* insn);

void LW(Memory* mem, Instruction* insn);
void LBU(Memory* mem, Instruction* insn);

void SB(Memory* mem, Instruction* insn);
void SW(Memory* mem, Instruction* insn);

void ADDI(Memory* mem, Instruction* insn);
void SLTIU(Memory* mem, Instruction* insn);
void XORI(Memory* mem, Instruction* insn);
void ANDI(Memory* mem, Instruction* insn);
void SLLI(Memory* mem, Instruction* insn);
void SRLI(Memory* mem, Instruction* insn);
void SRAI(Memory* mem, Instruction* insn);

void ADD(Memory* mem, Instruction* insn);
void SUB(Memory* mem, Instruction* insn);
void SLTU(Memory* mem, Instruction* insn);
void OR(Memory* mem, Instruction* insn);
void AND(Memory* mem, Instruction* insn);

void MUL(Memory* mem, Instruction* insn);
void DIVU(Memory* mem, Instruction* insn);

void LRW(Memory* mem, Instruction* insn);
void AMOSWAP(Memory* mem, Instruction* insn);

void ECALL(Memory* mem, Instruction* insn);
}

#endif //FUNCTIONS_H