#! /bin/bash

#SBATCH --job-name=MergeSort
#SBATCH --partition=Centaurus
#SBATCH --time=02:00:00
#SBATCH --mem=4G

g++ -o merge-output merge-sort.cpp

./merge-output 10
./merge-output 100
./merge-output 1000
./merge-output 10000
./merge-output 100000
./merge-output 1000000
./merge-output 10000000
./merge-output 100000000
./merge-output 1000000000
