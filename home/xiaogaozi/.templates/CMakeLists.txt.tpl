cmake_minimum_required(VERSION 2.8)
project(Alist C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-Wall")

add_executable(alist alist.c)

# enable_testing()
# add_test(test alist)
