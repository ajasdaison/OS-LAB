#!/bin/bash

echo "Enter the number:"
read num

if [ $((num % 2)) -eq 0 ]; then
  echo "Number is even"
else
  echo "Number is odd"
fi
