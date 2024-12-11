cmake_minimum_required(VERSION 3.5.0)
project(test VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED) 

add_executable(a.out test.cpp)

target_link_libraries(a.out $(GTEST_LIBRARIES))

enable_testing()

add_test(add a.out)
