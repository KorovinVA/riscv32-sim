#include "kernel.h"

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
    uint64_t instExec  = 0;
    uint64_t instCache = 0;

    try
    {
        while(instExec < 6029818)
        {
            Instruction* insn = nullptr;

            if(executed.count(mem->getPc()) <= 0)
            {
                //Instruction hasn't been decoded yet
                instCache++;

                insn = new Instruction(mem->PullNextInsn(), mem->getPc());
                executed.insert(std::pair<uint32_t, Instruction*>(mem->getPc(), insn));
            }
            else
            {
                insn = executed[mem->getPc()];
            }

            if(trEn)
            {
                DumpExecInsn(insn);
            }

            instExec++;
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
            std::cout << std::dec << "Executed: " << instExec << "\n Cached: " <<
               instCache << std::endl;    
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