cmake_minimum_required(VERSION 3.21)  # Bump for better VS 2022 support
project(CraftingInterpreters LANGUAGES CXX)

# Use VCPKG only if needed
if(EXISTS "C:/repos/vcpkg-master/scripts/buildsystems/vcpkg.cmake")
    set(CMAKE_TOOLCHAIN_FILE "C:/repos/vcpkg-master/scripts/buildsystems/vcpkg.cmake")
endif()

# Enable debug symbols and configure runtime
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
add_compile_options(
    "$<$<CONFIG:Debug>:/Zi>"          # Debug symbols
    "$<$<CONFIG:Debug>:/Od>"          # Disable optimizations
    "$<$<CONFIG:Release>:/O2>"
    /EHsc
    /W4
    /permissive-
    /std:c++latest
)

# Module-specific settings (for .ixx files)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Debug configuration flags
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "/DEBUG:FULL")

# Dependency handling
set(GFLAGS_USE_TARGET_NAMESPACE ON)
set(glog_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/share/glog")
set(gflags_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/share/gflags")
find_package (glog CONFIG REQUIRED)
find_package (gflags CONFIG REQUIRED)
file(GLOB VCPKG_DLLS "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/bin/*.dll")
file(COPY ${VCPKG_DLLS} DESTINATION "${CMAKE_BINARY_DIR}/Debug")

# Main executable
add_executable(CraftingInterpretersCpp
    "main.cpp"
    "chunk.ixx"
    "Common.ixx" 
    "Debug.ixx"
    "debug.cpp"
    "Value.ixx" 
    "RunLengthEncoding.ixx" 
    "Vm.ixx" "Vm.cpp" 
    "Stack.ixx" "Stack.cpp"
)

target_link_libraries(CraftingInterpretersCpp
    PRIVATE glog::glog gflags::gflags
)

# Copy DLLs only in Debug (adjust paths as needed)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    file(GLOB VCPKG_DLLS "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/debug/bin/*.dll")
    file(COPY ${VCPKG_DLLS} DESTINATION "${CMAKE_BINARY_DIR}/Debug")
endif()


#include(FetchContent)
#
#FetchContent_Declare(
#  Catch2
#  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#  GIT_TAG        v3.7.1
#)
#
#add_executable(tests
#    "test/RunLengthEncoding_test.cpp" "RunLengthEncoding.ixx" "Vm.cpp" "Stack.ixx" "Stack.cpp")
#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)