cmake_minimum_required(VERSION 3.15)

project(otus_hw01 VERSION 0.0.1)

add_executable(magic_squares "magic_squares.cpp")
set_target_properties(magic_squares PROPERTIES CXX_STANDARD 20 REQUIRED ON)

