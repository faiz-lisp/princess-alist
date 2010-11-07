cmake_minimum_required(VERSION 2.8)
project(Alist C)
add_executable(alist alist.c)

set(CMAKE_BUILD_TYPE Debug CACHE STRING
    "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
set(CMAKE_CXX_FLAGS "-Wall"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
# set(CMAKE_EXE_LINKER_FLAGS "-L -l"
#     CACHE STRING "Flags used by the compiler during Release with Debug Info builds." FORCE)

# enable_testing()
# add_test(test alist)
