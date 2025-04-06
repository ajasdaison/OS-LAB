#!/bin/bash

# --- FCFS DISK SHED (exp10_a.c) ---
echo "Compiling the Fcfs Disk (exp10_a) ..."
gcc src/exp10_a.c -o src/exp10_a

echo "Running exp10_a.c ...."
./src/exp10_a <<EOF
3
4
3
4
4
EOF

echo "________________________________"

# --- SCAN DISK SHED (exp10_a.c) ---
echo "Compiling the Scan Disk (exp10_b) ..."
gcc src/exp10_b.c -o src/exp10_b

echo "Running exp10_b.c ...."
./src/exp10_b <<EOF
3
4
3
4
4
EOF
