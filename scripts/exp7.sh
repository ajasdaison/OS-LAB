#!/bin/bash

# --- FIRST FIT (exp7_a.c) ---
echo "Compiling the First Fit (exp7_a) ..."
gcc src/exp7_a.c -o src/exp7_a

echo "Running exp7_a.c ...."
./src/exp7_a <<EOF
3
4
3
4
4
5
3
2
4
EOF
