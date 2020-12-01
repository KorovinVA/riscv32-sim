#include "memory.h"

Memory::Memory(uint32_t entry, std::vector<uint8_t>* rawData) : 
    pc(entry),
    data(),
    ax()
{
    data.resize(rawData->size());
    memcpy(&(data[0]), (void*)(rawData->data()), rawData->size());

    //Stack pointer, seems wrong :(
    ax[2] =  entry;
}

uint32_t Memory::PullNextInsn() const
{
    uint32_t byte_1 = data[pc];
    uint32_t byte_2 = data[pc + 1] << 8;
    uint32_t byte_3 = data[pc + 2] << 16;
    uint32_t byte_4 = data[pc + 3] << 24;

    uint32_t dword = byte_1 + byte_2 + byte_3 + byte_4;
    return dword;
}

uint32_t Memory::getPc() const
{
    return pc;
}

uint32_t Memory::getReg(uint32_t num) const
{
    return ax[num];
}

uint32_t Memory::load(uint32_t addr, uint8_t size) const
{
    if(size == 4)
    {
        addr = addr / 4;
        uint32_t* memory = (uint32_t*)(data.data());
        return memory[addr];
    }
    else
    {
        throw std::string("Unknown load size");
    }
    return -1;
}

void Memory::store(uint32_t addr, uint32_t val, uint8_t size)
{
    if(size == 4)
    {
        addr = addr / 4;
        uint32_t* memory = (uint32_t*)(data.data());
        memory[addr] = val;
    }
    else
    {
        throw std::string("Unknown store size");
    }
}


void Memory::setPc(uint32_t nPc)
{
    pc = nPc;
}


void Memory::setReg(uint32_t dst, uint32_t val)
{
    if(dst >= 32)
    {
        throw std::string("Trying to write in invalid register");
    }
    if(dst != 0)
    {
        ax[dst] = val;
    }
}

Memory::~Memory()
{}