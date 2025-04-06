#!/bin/bash

echo "Enter the value for a:"
read a

echo "Enter the value for b:"
read b

echo "Enter operator (+, -, *, /):"
read op

case $op in
+) c=$(expr $a + $b) ;;
-) c=$(expr $a - $b) ;;
\*) c=$(expr $a \* $b) ;;
/) c=$(expr $a / $b) ;;
*)
  echo "Invalid operator"
  exit 1
  ;;
esac

echo "Result: $c"
