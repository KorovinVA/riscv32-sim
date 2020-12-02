#include "memory.h"

Memory::Memory(uint32_t entry, std::vector<uint8_t>* rawData) : 
    pc(entry),
    ax()
{
    dataByte = new uint8_t[rawData->size()];
    dataWord = (uint32_t*)dataByte;

    memcpy(dataByte, (void*)(rawData->data()), rawData->size());

    //Stack pointer, seems wrong :(
    ax[2] =  5000;
    //Gloabal pointer, idk what to do :(
    ax[3]  = 533368;
}

uint32_t Memory::PullNextInsn() const
{
    return dataWord[pc / 4];
}

uint32_t Memory::getPc() const
{
    return pc;
}

uint32_t Memory::getReg(uint32_t num) const
{
    return ax[num];
}

uint32_t Memory::loadByte(uint32_t addr) const
{
    return dataByte[addr];
}

uint32_t Memory::loadWord(uint32_t addr) const
{
    addr /= 4;
    return dataWord[addr];
}

void Memory::storeWord(uint32_t addr, uint32_t val)
{
    addr /= 4;
    dataWord[addr] = val;
}

void Memory::storeByte(uint32_t addr, uint32_t val)
{
    dataByte[addr] = (uint8_t)val;
}

void Memory::UpdatePc()
{
    pc += 4;
}

void Memory::setPc(uint32_t nPc)
{
    pc = nPc;
}

void Memory::setReg(uint32_t dst, uint32_t val)
{
    if(dst != 0)
    {
        ax[dst] = val;
    }
}

Memory::~Memory()
{
    delete [] dataByte;
}