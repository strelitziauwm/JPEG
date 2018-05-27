cmake_minimum_required(VERSION 2.8)

project(jpeg_reader)

#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(SOI)

add_library(jpeg_file_class ${PROJECT_SOURCE_DIR}/src/jpeg.cpp)
add_executable(jpeg_reader ${PROJECT_SOURCE_DIR}/src/jpeg_reader.cpp)

target_link_libraries (jpeg_reader  soi_reader jpeg_file_class)
