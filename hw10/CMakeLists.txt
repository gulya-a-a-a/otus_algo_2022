cmake_minimum_required(VERSION 3.15)

project(hw10 VERSION 0.0.1)

add_executable(bst "bst.cpp")
set_target_properties(bst PROPERTIES CXX_STANDARD 20 REQUIRED ON)