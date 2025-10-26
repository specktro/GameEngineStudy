cmake_minimum_required(VERSION 3.20)
project(GameEngineStudy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Vector math executable
add_executable(vector_test
        01_MathFoundations/vectors/vector2d.cpp
        01_MathFoundations/vectors/vector3d.cpp
        01_MathFoundations/vectors/main.cpp)

target_include_directories(vector_test PRIVATE 01_MathFoundations/vectors)

# C++ assessment executable
add_executable(cpp_assessment
        02_CppRefresh/modern_features/cpp_assessment.cpp
)

add_executable(matrix_test
        01_MathFoundations/vectors/vector2d.cpp
        01_MathFoundations/vectors/vector3d.cpp
        01_MathFoundations/matrices/matrix3x3.cpp
        01_MathFoundations/matrices/test_matrix3x3.cpp)

target_include_directories(matrix_test PRIVATE 01_MathFoundations/matrices)