#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <array>

class Memory
{
public:
    Memory(uint32_t entry, std::vector<uint8_t>* rawData);
    uint32_t PullNextInsn();
    ~Memory();
private:
    std::vector<uint8_t> data;
    std::array<uint32_t, 32> intRegs;

    uint32_t pc;
    void Decode();
};

#endif //MEMORY_H