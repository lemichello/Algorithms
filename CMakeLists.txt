cmake_minimum_required(VERSION 3.17)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithms main.cpp bloom-filter/bloom-filter.h bloom-filter/storage/storage.h bloom-filter/storage/storage.cpp bloom-filter/bloom-filter.cpp)