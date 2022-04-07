cmake_minimum_required(VERSION 3.15)

project(arrays VERSION 0.0.1)

add_executable(arrays "main.cpp")
set_target_properties(arrays PROPERTIES CXX_STANDARD 17 REQUIRED ON)