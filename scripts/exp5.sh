#!/bin/bash

# Compile the C program (if not already compiled)
gcc -o exp5 exp5.c -lpthread -Wall

# Run the program and pass "3" as input
echo "3" | ./exp5
