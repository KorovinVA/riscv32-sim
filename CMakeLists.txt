cmake_minimum_required(VERSION 3.10)

project(riscv)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-pthread")

include_directories(${CMAKE_SOURCE_DIR}/llvm-project/llvm/include)
include_directories(${CMAKE_SOURCE_DIR}/llvm-project/build/include)
link_directories(${CMAKE_SOURCE_DIR}/llvm-project/build/lib)

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
                 sim/src/instruction.cpp
                 sim/src/parser.cpp
                 sim/src/readelf.cpp
		 sim/src/converter.cpp
		 sim/src/backend.cpp
                 sim/inc/instruction.h
                 sim/inc/parser.h
                 sim/inc/readelf.h
		 sim/inc/converter.h
		 sim/inc/macro.h
		 sim/inc/backend.h)
add_executable(riscv ${ELFIO} ${SRC})

target_include_directories(riscv PRIVATE ELFIO/)
target_link_libraries(riscv libLLVMCore.a)
target_link_libraries(riscv libLLVMRemarks.a)
target_link_libraries(riscv libLLVMSupport.a)
target_link_libraries(riscv libLLVMBinaryFormat.a)
target_link_libraries(riscv libLLVMBitstreamReader.a)
target_link_libraries(riscv tinfo)

message(STATUS "EXECUTABLE PATH ${PROJECT_BINARY_DIR}")

foreach(source IN LISTS ELFIO SRC)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()


if (WIN32)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT riscv)
endif()

#message(STATUS  "|  SYSTEM              ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}")
#message(STATUS  "|  COMPILER            ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
#message(STATUS  "|  BUILD_TYPE          ${CMAKE_BUILD_TYPE}")
