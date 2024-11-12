# CMakeList.txt : CMake project for CraftingInterpretersCpp
cmake_minimum_required (VERSION 3.12)

if (MSVC)
    add_compile_options(
        /EHsc       # Exception handling
        /MD         # Multi-threaded DLL runtime
        /std:c++latest 
        /W4         # Warning level 4
    )
endif()


# Add source to this project's executable.
add_executable(CraftingInterpretersCpp 
    "CraftingInterpretersCpp.cpp"
    "chunk.ixx"
    "common.ixx" "debug.ixx" "debug.cpp")

set_property(TARGET CraftingInterpretersCpp PROPERTY CXX_STANDARD 20)