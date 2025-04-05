#!/bin/bash

# Compile the C program
gcc src/exp6_a.c -o src/exp6_a

# Run the compiled program and provide inputs
./src/exp6_a <<EOF
4
5
3
8
6
EOF
