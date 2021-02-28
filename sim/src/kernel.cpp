#include "../inc/kernel.h"

Kernel::Kernel(Memory* memory, bool tracing):
    trEn(tracing),
    executed()
{
    mem = memory;

    if(trEn)
    {
        state.open("riscv.state");
        if (!state.is_open())
        {
            throw std::string("Cannot open state file");
        }
    }
}

void Kernel::Run()
{
    try
    {
        while(1)
        {
            Instruction* insn = nullptr;
            uint32_t pc = mem->getPc();

            if(executed.count(pc) <= 0)
            {
                //Instruction hasn't been decoded yet
                insn = new Instruction(mem->pullNextInsn(), pc);
                executed.insert(std::pair<uint32_t, Instruction*>(pc, insn));
            }
            else
            {
                insn = executed[pc];
            }
            if(trEn)
            {
                DumpExecInsn(insn);
            }

            insn->process(mem, insn);
        
            if(trEn)
            {
                DumpChangedReg(insn);
            }
        }
    }
    catch (int a)
    {
        if (a == -1)
        {
            std::cout << "ECALL was called in " << std::hex << 
                mem->getPc() << std::endl;   
            return;
        }
    }
}

void Kernel::DumpExecInsn(Instruction* insn)
{
    state << insn->getName() << std::endl;
}

void Kernel::DumpChangedReg(Instruction* insn)
{
    if(insn->getRd() != 0)
    {
        state << std::hex << "\t" << insn->getRName(insn->getRd()) << " = " << "0x" <<
            std::setw(8) << std::setfill('0') << mem->getReg(insn->getRd()) << std::endl;
    }
}

Kernel::~Kernel()
{
    if(state.is_open())
    {
        state.close();
    }

    for(auto it : executed)
    {
        delete it.second;
    }
}