#! /bin/bash

#SBATCH --job-name=MergeSort
#SBATCH --partition=Centaurus
#SBATCH --time=02:00:00
#SBATCH --mem=2G

./merge-sort 10
./merge-sort 100
./merge-sort 1000
./merge-sort 10000
./merge-sort 100000
./merge-sort 1000000
./merge-sort 10000000
./merge-sort 100000000
./merge-sort 1000000000
