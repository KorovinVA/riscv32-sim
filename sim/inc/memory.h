#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <array>
#include <map>
#include <sstream>

#include <elfio/elfio.hpp>
#include "readelf.h"

class Memory
{
public:
    Memory(const std::string& elfFile);
    ~Memory();
private:
    char* data = nullptr;
    ElfReader elf;
};

#endif //MEMORY_H