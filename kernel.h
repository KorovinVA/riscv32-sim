#ifndef KERNEL_H
#define KERNEL_H

#include "memory.h"
#include "decoder.h"

class Kernel
{
public:
    Kernel(Memory* memory, bool tracing = false);
    ~Kernel();
    void Run();
private:
    Memory* mem;
    bool trEn;
};

#endif //KERNEL_H