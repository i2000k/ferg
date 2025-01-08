cmake_minimum_required(VERSION 3.29)
project(sort_files)

set(CMAKE_CXX_STANDARD 17)

add_executable(sort_files main.cpp
        file_organizer.cpp
        file_organizer.hpp)
