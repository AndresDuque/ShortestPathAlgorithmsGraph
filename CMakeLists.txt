cmake_minimum_required(VERSION 3.19)
project(ShortPathGraph)

set(CMAKE_CXX_STANDARD 14)

add_library(graph SHARED)

target_sources(graph PRIVATE
        src/Graph.cpp
        include/Graph.h
        )
target_include_directories(graph PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/>)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} graph)
