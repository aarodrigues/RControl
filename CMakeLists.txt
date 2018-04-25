cmake_minimum_required(VERSION 2.8)

project(RControl)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF)

SET( CMAKE_INCLUDE_CURRENT_DIR ON )
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/nlohmann/)
add_executable(${PROJECT_NAME}  "header/parsecommand.h" "header/serversocket.h" "source/serversocket.cpp" "source/parsecommand.cpp" "source/main.cpp")
