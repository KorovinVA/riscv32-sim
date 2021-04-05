#include "../inc/readelf.h"

ElfReader::ElfReader(const std::string& filename) :
    elfFileName(filename),
    execSections()
{
    if (!elfio.load(filename))
    {
        std::cerr << "Elf cannot be loaded!" << std::endl;
        exit(1);
    }
}

uint64_t ElfReader::getImageSize() const
{
    uint64_t size = 0;
    for (auto it : elfio.sections)
    {
        if ((it->get_flags() & SHF_ALLOC) != 0)
        {
            size = it->get_address() + it->get_size();
        }
    }
    return size;
}

uint64_t ElfReader::getEntryPoint() const
{
    return uint64_t(elfio.get_entry());
}

void ElfReader::load(uint8_t* mem)
{
    assert(mem != nullptr);

    for (auto it : elfio.sections)
    {
        if ((it->get_flags() & SHF_ALLOC) != 0 && it->get_data() != nullptr)
        {
            std::memcpy(mem + it->get_address(), it->get_data(), it->get_size());
        }
        if ((it->get_flags() & SHF_EXECINSTR) != 0)
        {
            SectionInfo sec;
            std::tie(sec.addr, sec.size, sec.name) = std::make_tuple(it->get_address(), it->get_size(), it->get_name());
            execSections.push_back(sec);
        }
    }
}

ElfReader::~ElfReader()
{}

