cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project (BookShelf LENGUAGES C++)
include_directories(include)
add_library(Bookshelf
	include/BookShelf.h
	src/BookShelf.cpp
)
add_library(Book
	include/Book.h
	src/Book.cpp
)
add_library(Date
	include/Date.h
	src/Date.cpp
)
add_executable(main
	src/main.cpp
)
target_link_libraries(Book
	Date
)
target_link_libraries(BookShelf
	Book
)
target_link_libraries(main
	BookShelf
)