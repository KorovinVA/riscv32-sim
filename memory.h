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

    uint32_t pullNextInsn()          const;
    uint32_t getPc()                 const;
    uint32_t getReg(uint32_t num)    const;
    uint32_t loadByte(uint32_t addr) const;
    uint32_t loadWord(uint32_t addr) const;

    void     storeByte(uint32_t addr, uint32_t val);
    void     storeWord(uint32_t addr, uint32_t val);
    void     updatePc();
    void     setPc(uint32_t nPc);
    void     setReg(uint32_t dst, uint32_t val);
private:
    uint8_t*  dataByte = nullptr;
    uint32_t* dataWord = nullptr;

    std::array<uint32_t, 32> ax;
    uint32_t pc;
};

inline uint32_t Memory::pullNextInsn() const
{
    return dataWord[pc / 4];
}

inline uint32_t Memory::getPc() const
{
    return pc;
}

inline uint32_t Memory::getReg(uint32_t num) const
{
    return ax[num];
}

inline void Memory::updatePc()
{
    pc += 4;
}

inline void Memory::setPc(uint32_t nPc)
{
    pc = nPc;
}
inline void Memory::setReg(uint32_t dst, uint32_t val)
{
    if(dst != 0)
    {
        ax[dst] = val;
    }
}

#endif //MEMORY_H