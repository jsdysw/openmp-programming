# openmp-programming

* experiment environment 
	- CPU type : Intel(R) Core(TM) i5-5200U
	- number of cores : 2 core CPU
	- memory size : 4 GB
	- OS : Windows 8.1 K

## Prob1. Compute the number of ‘prime numbers’ between 1 and 200000.

![KakaoTalk_Photo_2022-05-19-03-02-35](https://user-images.githubusercontent.com/76895949/169112710-04570bb4-960d-4fda-bdbc-1f2826cb03a9.png)

	At cmd,
	(1) gcc prob1.c -fopenmp
	(2) a.exe <schedule option from 0 to 3> <number of threads>

## Prob2. Parallel PI calculation.

![KakaoTalk_Photo_2022-05-19-03-02-32](https://user-images.githubusercontent.com/76895949/169112644-8cc916f2-67e6-4a8a-865b-bccccac66f3d.png)

	At cmd,
	(1) gcc prob2.c -fopenmp
	(2) a.exe <schedule option from 0 to 3> <chunk size> <number of threads>
