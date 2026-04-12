cmake_minimum_required(VERSION 3.10)
project(Lab1_Project)
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

set(SOURCES
    lab1.cpp
    rect.cpp
    barrel.cpp
    matrix.cpp
    mystring.cpp
    textwrapper.cpp
)

add_executable(lab1_exe ${SOURCES})

set_target_properties(lab1_exe PROPERTIES OUTPUT_NAME "lab1")