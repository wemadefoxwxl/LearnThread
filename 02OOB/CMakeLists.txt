project(pas CXX)

set(CXX_FLAGS -g -Wall -std=c++11)
set(CMAKE_CXX_COMPILER "g++")
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(main main.cpp Thread.cpp)
target_link_libraries(main pthread)
add_executable(testfunctional  testfunctional.cpp)
