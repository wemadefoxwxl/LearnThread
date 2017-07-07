set(CXX_FLAGS -g -Wall)
set(CMAKE_CXX_COMPILER "gcc")
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(main main.c condition.c threadpool.c)
target_link_libraries(main pthread)
