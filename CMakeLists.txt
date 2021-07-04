cmake_minimum_required(VERSION 3.16)
project(RTSoft-TestTask)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic")

include_directories(include/)

file(GLOB SOURCES src/*.cpp)
file(COPY input.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(${PROJECT_NAME} ${SOURCES})
