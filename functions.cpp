#include "functions.h"

void Func::JAL(Memory* mem, Instruction* insn)
{
    mem->setReg(insn->getRd(), mem->getPc() + 4);
    mem->setPc(mem->getPc() + insn->getImm());
}

void Func::AUIPC(Memory* mem, Instruction* insn)
{
    uint32_t nPc = mem->getPc() + (insn->getImm() << 12);
    mem->setReg(insn->getRd(), nPc);
    mem->setPc(mem->getPc() + 4);
}

void Func::ADDI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) + insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::ANDI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) & insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::JALR(Memory* mem, Instruction* insn)
{
    uint32_t jump = mem->getReg(insn->getRs1()) + insn->getImm();
    jump <<= 1;
    jump >>= 1;

    mem->setReg(insn->getRd(), mem->getPc() + 4);
    mem->setPc(jump);
}

void Func::LW(Memory* mem, Instruction* insn)
{
    uint32_t addr = insn->getImm() + mem->getReg(insn->getRs1());
    mem->setReg(insn->getRd(), mem->load(addr, 4));
    mem->setPc(mem->getPc() + 4);
}

void Func::SUB(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) - mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}