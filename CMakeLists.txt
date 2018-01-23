cmake_minimum_required(VERSION 3.9)
project(kiss_tree C)

set(CMAKE_C_STANDARD 11)

add_executable(kiss_tree main.c kiss_tree.c kiss_tree.h)