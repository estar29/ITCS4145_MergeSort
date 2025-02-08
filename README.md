MERGE SORT ALGORITHM - ITCS 4145 001

RUNNING INSTRUCTIONS


On Terminal:

1. Ensure that you are in an appropriate directory or location to be able to run the code.

2. On the terminal, write the following command:

      g++ -o <output-file> merge-sort.cpp

3. To print the output, input the following.

      ./output-file (integer param for the array size, optional)


Benchmarking on Centaurus:

1. Log in to UNC-Charlotte’s Centaurus partition.

2. Once logged in, git clone the repository to your account.

3. Change your directory to the cloned merge sort repository.

4. To run the Slurm script, write the following:

     sbatch merge-script.sh

5. Regularly use the following command to check on the status of the job:

      squeue

6. Once you no longer see your job on the queue, write the following command to see the output:
	    slurm-<job number>.out



OUTPUT

https://docs.google.com/spreadsheets/d/1lPtA1Z1vcJYhx6YsKCQaHd8fzWz3G8f-XzIE9Z31iNY/edit?usp=sharing

The output from these charts appear to increase by a magnitude of 10 as the array size increases by a magnitude of 10.  This makes sense; the first 5 to 6 tests will run very quickly due to a smaller size and the efficient Merge Sort algorithm.  As the array size approaches the tens and hundreds of millions and a size of one billion, the computation time balloons up to minutes due to the sheer size of the array.
