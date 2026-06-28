# mini-hft-core

Educational C++ project for learning core components of trading systems:
orders, order books, tests, benchmarks and performance-oriented c++.

## Goals

The goal of this project is to gradually implement:
- order representation
- order book
- matching logic
- tests
- benchmarks

## Current status

Week 1:
- basic CMake project
- CLion/macOS development setup
- header-only `mini_hft` library
- `Order` model
- `Side` enum
- order validation helpers
- simple matching helpers
- tests via `assert` and CTest

## Requirements

- macOS on Apple Silicon
- CLion
- clang++
- CMake
- Git

## Build

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

## Run

```bash
./build/mini_hft_core
```

## Test

```bash
ctest --test-dir build --output-on-failure
```