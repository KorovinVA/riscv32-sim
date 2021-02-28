cmake_minimum_required(VERSION 3.10)

project(riscv)

include_directories("${PROJECT_SOURCE_DIR}/src")

set(HEADER_FILES src/functions.h
                 src/instruction.h
                 src/kernel.h
                 src/memory.h
                 src/readelf.h)

add_executable(riscv src/main.cpp
                     src/functions.cpp
                     src/instruction.cpp
                     src/kernel.cpp
                     src/memory.cpp
                     src/readelf.cpp
                     src/functions.h
                     src/instruction.h
                     src/kernel.h
                     src/memory.h
                     src/readelf.h)

if (WIN32)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT riscv)
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS  "|  BUILD_TYPE          ${PROJECT_SOURCE_DIR}")