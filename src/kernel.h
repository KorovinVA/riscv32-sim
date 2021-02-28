#ifndef KERNEL_H
#define KERNEL_H

#include <fstream>
#include <map>
#include <memory>

#include "memory.h"
#include "instruction.h"

class Kernel
{
public:
    Kernel(Memory* memory, bool tracing = false);
    ~Kernel();
    void Run();

    Memory* mem;
private:
    void DumpExecInsn(Instruction* insn);
    void DumpChangedReg(Instruction* insn);

    std::map<uint32_t, Instruction*> executed;
    const bool trEn;
    std::ofstream state;
};

#endif //KERNEL_H