cmake_minimum_required(VERSION 3.20)

project(mini_hft_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(mini_hft_core
        src/main.cpp
)
