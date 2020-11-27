#include "readelf.h"

ReadElf::ReadElf(const char* elf):
    m_err("ELF ERROR: "),
    m_sections(),
    m_strtable()
{
    OpenElf(elf);
    ReadHeader();

    for(int i = 0; i < m_ehdr.e_shnum; ++i)
    {
        SaveSection(i);
    }

    NameSections();
}

ReadElf::~ReadElf()
{
    fclose(m_elf);
}

void ReadElf::OpenElf(const char* elf)
{
    m_elf = fopen(elf, "rb");
    if(!m_elf)
    {
        throw m_err + std::string(std::strerror(errno));
    }
}

void ReadElf::ReadHeader()
{
    fread(&m_ehdr, sizeof(m_ehdr), 1, m_elf);
    if(m_ehdr.e_machine != EM_RISCV)
    {
        throw m_err + "only riscv is supported";
    }
}

void ReadElf::SaveSection(int secNum)
{
    std::unique_ptr<Section> sec(new Section);

    fseek(m_elf, m_ehdr.e_shoff + secNum * sizeof(sec->m_shdr), SEEK_SET);
    fread(&(sec->m_shdr), 1, sizeof(sec->m_shdr), m_elf);
    
    sec->m_data = calloc(1, sec->m_shdr.sh_size);
    fseek(m_elf, sec->m_shdr.sh_offset, SEEK_SET);
    fread(sec->m_data, 1, sec->m_shdr.sh_size, m_elf);

    m_sections.push_back(std::move(sec));
}

void ReadElf::NameSections()
{
    for(auto it = m_sections.rbegin(); it != m_sections.rend(); ++it)
    {
        Section* sec = it->get();

        //Section holds a string table
        if(sec->m_shdr.sh_type == SHT_STRTAB)
        {
            for(int i = 0; i < sec->m_shdr.sh_size; ++i)
            {
                m_strtable.push_back(*((char*)(sec->m_data) + i));
            }
        }
    }

    for(auto it = m_sections.begin(); it != m_sections.end(); ++it)
    {
        Section* sec = it->get();
        sec->name = m_strtable.data() + sec->m_shdr.sh_name;
    }

    //for(auto it = m_sections.begin(); it != m_sections.end(); ++it)
    //{
        //Section* sec = it->get();
        //std::cout << sec->name << std::endl;
    //}
}

void ReadElf::Disassembly()
{
}