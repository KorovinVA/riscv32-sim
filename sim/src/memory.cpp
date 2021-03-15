#include "../inc/memory.h"

Memory::Memory(const std::string& filename) :
    ax(),
    elf(filename)
{    
    unsigned imageSize = elf.getImageSize();
    data = new char[imageSize];
    elf.Load(data);
}

Memory::~Memory()
{
    delete[] data;
}