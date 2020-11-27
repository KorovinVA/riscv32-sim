#include "memory.h"

Memory::Memory(uint32_t entry, std::vector<uint8_t>* rawData) : 
    pc(entry),
    data()
{
    data.resize(rawData->size());
    memcpy(&(data[0]), (void*)(rawData->data()), rawData->size());
}

void Memory::Decode()
{
    for(int i = pc; i != data.size() - 4; i += 4)
    {
        uint32_t byte_1 = data[i];
        uint32_t byte_2 = data[i + 1] << 8;
        uint32_t byte_3 = data[i + 2] << 16;
        uint32_t byte_4 = data[i + 3] << 24;

        uint32_t dword = byte_1 + byte_2 + byte_3 + byte_4;

        std::cout << dword << std::endl;
    }
}

Memory::~Memory()
{
}