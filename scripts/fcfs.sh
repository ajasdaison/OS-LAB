#!/bin/bash

# Compile the C program
gcc exp6_a.c -o exp6_a

# Run the compiled program and provide inputs
./exp6_a <<EOF
4
5
3
8
6
EOF
