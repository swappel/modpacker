cmake_minimum_required(VERSION 3.10)
project(ModPacker)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(modpacker ${SOURCES})
