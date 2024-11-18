cmake_minimum_required(Version 3.10)

project(Studentu_duomenys)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

set(SOURCES
    Studentu_duomenys.cpp
    Stud.cpp
    FailoGeneravimas.cpp
    FailoNuskaitymas.cpp
    Mylib.h
    Stud.h
)

add_executable(studentai_program ${SOURCES})