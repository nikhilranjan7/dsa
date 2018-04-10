cmake_minimum_required(VERSION 3.10)
project(Lab_6)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Lab_6
        a.sh
        data.txt
        file.c
        implement.c
        implement.h
        makefile
        use.c
        use.h)
