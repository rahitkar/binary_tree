#! /bin/bash
rm -rf *.o
gcc -c $1.c
gcc -o $1 *.o
rm -rf *.o
./$1
rm $1