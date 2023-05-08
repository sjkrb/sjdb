
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
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

# Set C++ standard
set_target_properties(sjdb PROPERTIES
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
