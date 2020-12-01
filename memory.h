#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <array>
#include <map>

class Memory
{
public:
    Memory(uint32_t entry, std::vector<uint8_t>* rawData);
    ~Memory();

    uint32_t PullNextInsn() const;
    uint32_t getPc()        const;
    uint32_t getReg(uint32_t num) const;
    uint32_t load(uint32_t addr, uint8_t size) const;

    void     store(uint32_t addr, uint32_t val, uint8_t size);
    void     setPc(uint32_t nPc);
    void     setReg(uint32_t dst, uint32_t val);
private:
    std::vector<uint8_t> data;
    std::array<uint32_t, 32> ax;

    uint32_t pc;
};

#endif //MEMORY_H