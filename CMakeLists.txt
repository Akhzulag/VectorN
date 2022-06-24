cmake_minimum_required(VERSION 3.21)
project(VectorN)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./googletest-main)
set(LIBRARIES
        gtest
        pthread)


add_executable(VectorN TEST.cpp Vector.h Vector.cpp)
target_link_libraries(VectorN ${LIBRARIES})