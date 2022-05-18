# openmp-programming

* experiment environment 
	- CPU type : Intel(R) Core(TM) i5-5200U
	- number of cores : 2 core CPU
	- memory size : 4 GB
	- OS : Windows 8.1 K

## Problem1. Compute the number of ‘prime numbers’ between 1 and 200000.

	At cmd,
	(1) gcc prob1.c -fopenmp
	(2) a.exe <schedule option from 0 to 3> <number of threads>

## Problem2. Parallel PI calculation.

	At cmd,
	(1) gcc prob2.c -fopenmp
	(2) a.exe <schedule option from 0 to 3> <chunk size> <number of threads>
