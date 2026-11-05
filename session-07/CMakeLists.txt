cmake_minimum_required(VERSION 3.22)
project(Session07 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
add_executable(main
    source/main.cpp
    source/Tempo.cpp
)
target_compile_features(main PRIVATE cxx_std_17)
