cmake_minimum_required(VERSION 2.8)
project(Prova-Intermedia-2023-2024)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Prova-Intermedia-2023-2024 ${SOURCES})