file(GLOB SRCS *.cpp *.h)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(SrcLib ${SRCS})
include_directories(../)

target_link_libraries(SrcLib utils)
set_target_properties(SrcLib PROPERTIES LINKER_LANGUAGE CXX)
