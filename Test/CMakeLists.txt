cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
project(test)

find_package(Catch2)

add_executable(test
    tst_interpreter.cpp
)
target_include_directories(test PRIVATE ../)
target_link_libraries (test PRIVATE SrcLib Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(test)
