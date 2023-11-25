cmake_minimum_required(VERSION 3.5.0)
project(progetto_intermedio VERSION 0.1.0 LANGUAGES C CXX)

add_executable(progetto_intermedio src/main.cpp src/Book.cpp src/Bate.cpp src/BookShelf.cpp)

include_directories([SYSTEM] "include")
