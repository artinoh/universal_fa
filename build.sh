#!/bin/bash

# Set the build directory and CMake options
BUILD_DIR="./build"
CMAKE_OPTIONS="-DCMAKE_BUILD_TYPE=Release"

# Create the build directory if it does not exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Run CMake to generate the Makefile
cd "$BUILD_DIR"
cmake .. $CMAKE_OPTIONS

# Build the project using the Makefile
make
