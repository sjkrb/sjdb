file(GLOB SRCS *.cpp *.h)

add_library(utils ${SRCS})

set_target_properties(utils PROPERTIES LINKER_LANGUAGE CXX)


