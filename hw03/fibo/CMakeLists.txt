find_package(Boost 1.74.0 REQUIRED)

add_executable(fibo "fibo.cpp")
set_target_properties(fibo PROPERTIES CXX_STANDARD 17 REQUIRED ON)