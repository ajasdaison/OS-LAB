#!/bin/bash

echo "Enter two numbers:"
read a b

if [ $a -gt $b ]; then
  echo "$a is bigger"
else
  echo "$b is bigger"
fi
