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
    "main.cpp"
    "chunk.ixx"
    "Common.ixx" 
    "Debug.ixx"
    "debug.cpp"
    "Value.ixx" 
    "RunLengthEncoding.ixx")

set_property(TARGET CraftingInterpretersCpp PROPERTY CXX_STANDARD 20)


# UnitTesting
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests 
    "test/RunLengthEncoding_test.cpp" "RunLengthEncoding.ixx")
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)