cmake_minimum_required(VERSION 3.10)

project(MainDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Main main.cpp)

target_include_directories(Main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          )