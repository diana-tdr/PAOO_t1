cmake_minimum_required(VERSION 3.10)

project(MainDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(MusicAlbum)

add_executable(MainDemo main.cpp)

target_link_libraries(MainDemo PUBLIC MusicAlbum)
target_link_libraries(MainDemo PUBLIC VinylAlbum)
target_link_libraries(MainDemo PUBLIC DigitalAlbum)

target_include_directories(MainDemo PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MusicAlbum"
                          )