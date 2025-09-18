# Vector math exercises
cmake_minimum_required(VERSION 3.20)

add_executable(vector_test
        vectors/vector2d.cpp
        vectors/main.cpp
)

target_include_directories(vector_test PRIVATE vectors)