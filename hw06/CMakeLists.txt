cmake_minimum_required(VERSION 3.15)

project(simple_sorts VERSION 0.0.1)

add_executable(simple_sorting "main.cpp")
target_compile_options(simple_sorting PUBLIC "-O0")