cmake_minimum_required(VERSION 3.25)
project(AMIT_C_Programming_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AMIT_C_Programming_Project
        "bin/Debug/AMIT-C Programming Project.exe"
        obj/Debug/main.o
        obj/Debug/SDB.o
        obj/Debug/SDBAPP.o
        "AMIT-C Programming Project.cbp"
        "AMIT-C Programming Project.depend"
        "AMIT-C Programming Project.layout"
        main.c
        SDB.c
        SDB.h
        SDBAPP.c
        STD.h)
