#!/bin/bash
echo "Compiling"
gcc -O3 -fPIC -w -Wno-incompatible-pointer-types -Wno-cpp -c bench.c -o bench.o
echo "Linking"
gcc bench.o -o bench -lgsl -lgslcblas -lcblas -L/usr/lib -lm