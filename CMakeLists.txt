cmake_minimum_required(VERSION 3.10)

project(riscv)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(ELFIO        ELFIO/elfio/elf_types.hpp
                 ELFIO/elfio/elfio.hpp
                 ELFIO/elfio/elfio_array.hpp
                 ELFIO/elfio/elfio_dump.hpp
                 ELFIO/elfio/elfio_dynamic.hpp
                 ELFIO/elfio/elfio_header.hpp
                 ELFIO/elfio/elfio_modinfo.hpp
                 ELFIO/elfio/elfio_note.hpp
                 ELFIO/elfio/elfio_relocation.hpp
                 ELFIO/elfio/elfio_section.hpp
                 ELFIO/elfio/elfio_segment.hpp
                 ELFIO/elfio/elfio_strings.hpp
                 ELFIO/elfio/elfio_symbols.hpp
                 ELFIO/elfio/elfio_utils.hpp
                 ELFIO/elfio/elfio_version.hpp)
set(SRC          sim/src/main.cpp
                 sim/src/functions.cpp
                 sim/src/instruction.cpp
                 sim/src/kernel.cpp
                 sim/src/memory.cpp
                 sim/src/readelf.cpp
                 sim/inc/functions.h
                 sim/inc/instruction.h
                 sim/inc/kernel.h
                 sim/inc/memory.h
                 sim/inc/readelf.h)
add_executable(riscv ${ELFIO} ${SRC})

foreach(source IN LISTS ELFIO SRC)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()


if (WIN32)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT riscv)
endif()


message(STATUS  "|  BUILD_TYPE          ${PROJECT_SOURCE_DIR}")