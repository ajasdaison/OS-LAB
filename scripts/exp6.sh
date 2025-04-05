#!/bin/bash

# --- FCFS (exp6_a.c) ---
echo "Compiling exp6_a.c (FCFS)..."
gcc src/exp6_a.c -o src/exp6_a

echo "Running exp6_a (FCFS)..."
./src/exp6_a <<EOF
4
5
3
8
6
EOF

echo "----------------------------------------"

# --- SJF (exp6_b.c) ---
echo "Compiling exp6_b.c (SJF)..."
gcc src/exp6_b.c -o src/exp6_b

echo "Running exp6_b (SJF)..."
./src/exp6_b <<EOF
4
5
3
8
6
EOF

echo "----------------------------------------"

# --- ROUND ROBIN (exp6_c.c) ---
echo "Compiling exp6_c (ROUND ROBIN)..."
gcc src/exp6_c.c -o src/exp6_c

echo "Running exp6_c.c ......"
./src/exp6_c <<EOF
4
5
4
5
6
3
EOF
