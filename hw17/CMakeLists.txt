cmake_minimum_required(VERSION 3.15)

project(hw17 VERSION 0.0.1)

add_executable(boyer_moore "boyer_moore.cpp")
set_target_properties(boyer_moore PROPERTIES CXX_STANDARD 20 REQUIRED ON)