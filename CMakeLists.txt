cmake_minimum_required(VERSION 3.20)

project(mini_hft_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(mini_hft INTERFACE
        tests/order_tests.cpp)

target_include_directories(mini_hft INTERFACE
        include
)

add_executable(mini_hft_core
        src/main.cpp
)

target_link_libraries(mini_hft_core PRIVATE
    mini_hft
)

enable_testing()
add_subdirectory(tests)