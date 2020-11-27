#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cstdint>
#include <cstring>
#include <iostream>

class Memory
{
public:
    Memory(uint32_t entry, std::vector<uint8_t>* rawData);
    ~Memory();
private:
    std::vector<uint8_t> data;
    uint32_t pc;

    void Decode();
};

#endif //MEMORY_H