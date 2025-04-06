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
