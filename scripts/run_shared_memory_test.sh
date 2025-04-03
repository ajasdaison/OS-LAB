#!/bin/bash

# Exit script on any command failure
set -e

# Compile the shared memory writer and reader
gcc src/exp4_shr_writer.c -o src/exp4_shr_writer
gcc src/exp4_shr_reader.c -o src/exp4_shr_reader

# Run the writer with predefined input
echo "Automated Input for Shared Memory Test" | ./src/exp4_shr_writer

# Run the reader to retrieve data from shared memory
./src/exp4_shr_reader
