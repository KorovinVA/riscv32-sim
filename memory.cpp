#include "memory.h"

Memory::Memory(uint32_t entry, std::vector<uint8_t>* rawData) : 
    pc(entry),
    data()
{
    data.resize(rawData->size());
    memcpy(&(data[0]), (void*)(rawData->data()), rawData->size());
}

uint32_t Memory::PullNextInsn()
{
    uint32_t byte_1 = data[pc];
    uint32_t byte_2 = data[pc + 1] << 8;
    uint32_t byte_3 = data[pc + 2] << 16;
    uint32_t byte_4 = data[pc + 3] << 24;

    uint32_t dword = byte_1 + byte_2 + byte_3 + byte_4;
    return dword;
}

Memory::~Memory()
{
}