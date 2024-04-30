#!/bin/bash
set -u
fibonacci(){
        n=$1
        a=0
        b=1
        echo -n "Fibonacci series upto the $n terms: "
        for ((i=0;i<n;i++)); do
                echo -n "$a  "
                temp=$((a+b))
                a=$b
                b=$temp
        done
        echo ""
}
echo -n "Enter total number of terms: "
read n
if [ $n -le 0 ]; then
        echo "Number of terms must be greater than 0!"
else
        fibonacci $n
fi


