#!/bin/bash

# Exit on error
set -e

echo "Compiling Shared Memory Writer and Reader..."
gcc -Wall -Wextra -o src/exp4_shr_writer src/exp4_shr_writer.c
gcc -Wall -Wextra -o src/exp4_shr_reader src/exp4_shr_reader.c

echo "Running Shared Memory Writer..."
./src/exp4_shr_writer

echo "Running Shared Memory Reader..."
./src/exp4_shr_reader
