cmake_minimum_required(VERSION 3.15)

project(hw12 VERSION 0.0.1)

add_executable(hashTable "main.cpp")
set_target_properties(hashTable PROPERTIES CXX_STANDARD 17 REQUIRED ON)