cmake_minimum_required(VERSION 3.10)
project(MARTINS_432_FLOW VERSION 2.6.0 LANGUAGES CXX)

# 1. Sovereignty Configurations (Rigid Constraints)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 2. Compilation Flags (Zero-STL | Zero-Exceptions | NASA-Grade)
if(MSVC)
    add_compile_options(/W4 /WX /GR- /EHs-)
else()
    add_compile_options(-Wall -Wextra -Werror -fno-exceptions -fno-rtti -O3)
endif()

# 3. Directory Inclusion (Root)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 4. Main Executable Definition
add_executable(sigma_clock main.cpp)

# 5. Build Integrity Check
message(STATUS "-----------------------------------------------")
message(STATUS "Σ-CLOCK v2.6.0 BUILD SYSTEM")
message(STATUS "Constraints: Zero-STL, Zero-Heap, No-Exceptions")
message(STATUS "-----------------------------------------------")
