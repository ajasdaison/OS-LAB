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

echo "_______________________________"

# --- WORST FIT (exp7_b.c) ---
echo "Compiling the Worst Fit (exp7_b) ..."
gcc src/exp7_b.c -o src/exp7_b

echo "Running exp7_b.c ...."
./src/exp7_b <<EOF
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

echo "_______________________________"

# --- BEST FIT (exp7_c.c) ---
echo "Compiling the Best Fit (exp7_c) ..."
gcc src/exp7_c.c -o src/exp7_c

echo "Running exp7_c.c ...."
./src/exp7_c <<EOF
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
