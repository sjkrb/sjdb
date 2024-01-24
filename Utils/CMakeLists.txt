file(GLOB SRCS *.cpp *.h)

set(CMAKE_CXX_STANDARD 20)
add_library(utils ${SRCS})
set_target_properties(utils PROPERTIES LINKER_LANGUAGE CXX)



