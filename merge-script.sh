#! /bin/bash

#SBATCH --job-name=MergeSort
#SBATCH --partition=Centaurus
#SBATCH --time=02:00:00
#SBATCH --mem=2G

./merge-sort.sh 10
./merge-sort.sh 100
./merge-sort.sh 1000
./merge-sort.sh 10000
./merge-sort.sh 100000
./merge-sort.sh 1000000
./merge-sort.sh 10000000
./merge-sort.sh 100000000
./merge-sort.sh 1000000000
