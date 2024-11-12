# CMakeList.txt : CMake project for CraftingInterpretersCpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)



# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CraftingInterpretersCpp")

# Add source to this project's executable.
add_executable (CraftingInterpretersCpp "CraftingInterpretersCpp.cpp" "CraftingInterpretersCpp.h"  "common.ixx")

set_property(TARGET CraftingInterpretersCpp PROPERTY CXX_STANDARD 20)

# TODO: Add tests and install targets if needed.
