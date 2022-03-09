cmake_minimum_required(VERSION 3.15)

project(hw04 VERSION 0.0.1)

add_executable(bitboard "bitboard.cpp")
set_target_properties(bitboard PROPERTIES CXX_STANDARD 17 REQUIRED on)