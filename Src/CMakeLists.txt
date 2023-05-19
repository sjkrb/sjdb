file(GLOB SRCS *.cpp *.h)

add_library(SrcLib ${SRCS})
include_directories(../)

set_target_properties(SrcLib PROPERTIES LINKER_LANGUAGE CXX)


