cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
set(CMAKE_C_FLAGS "-Wall" CACHE STRING "Flags used by the compiler during all build types.")

add_executable(alist alist.c)

# enable_testing()
# add_test(test alist)

project(Alist C)
