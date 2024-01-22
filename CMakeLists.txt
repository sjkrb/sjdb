cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Catch2 REQUIRED)
project(SJDB)

# Add source files
set(SOURCES
    main.cpp
)

# Add header files
set(HEADERS
)


# Add include directories
#include_directories(.)

# Create executable target
add_executable(sjdb ${SOURCES} ${HEADERS})

add_subdirectory(Src)
target_link_libraries(sjdb SrcLib)
add_subdirectory(Utils)
add_subdirectory(Test)
#target_link_libraries(sjdb utils)


set_target_properties(sjdb PROPERTIES
    CXX_STANDARD_REQUIRED YES
)
