#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


long num_steps = 10000000;
double step;


// schedule type, argv[1]
// 1(static), 2(dynamic), 3(guided)

// chunk size, argv[2]
// number of thread, argv[3]

int NUM_THREAD;
int SCHEDULE;
int CHUNK_SIZE;

int main(int argc, char* argv[])
{
	SCHEDULE = atoi(argv[1]);
	CHUNK_SIZE = atoi(argv[2]);
	NUM_THREAD = atoi(argv[3]);

	long i; double x, pi, sum = 0.0;
	double start_time, end_time;

	start_time = omp_get_wtime();
	step = 1.0 / (double)num_steps;


	switch (SCHEDULE) {
	case 1:
#pragma omp parallel for reduction(+:sum) private(x) schedule(static, CHUNK_SIZE)
		for (i = 0; i < num_steps; i++) {
			x = (i + 0.5) * step;
			sum = sum + 4.0 / (1.0 + x * x);
		}
		pi = step * sum;
		break;

	case 2:
#pragma omp parallel for reduction(+:sum) private(x) schedule(dynamic, CHUNK_SIZE)
		for (i = 0; i < num_steps; i++) {
			x = (i + 0.5) * step;
			sum = sum + 4.0 / (1.0 + x * x);
		}
		pi = step * sum;
		break;

	case 3:
#pragma omp parallel for reduction(+:sum) private(x) schedule(guided, CHUNK_SIZE)
		for (i = 0; i < num_steps; i++) {
			x = (i + 0.5) * step;
			sum = sum + 4.0 / (1.0 + x * x);
		}
		pi = step * sum;
		break;
	default:
		return 1;
	}

	end_time = omp_get_wtime();
	double timeDiff = end_time - start_time;
	
	printf("Schedule option : %d\n", SCHEDULE);
	printf("Chunk size : %d\n", CHUNK_SIZE);
	printf("Number of threads : %d\n", NUM_THREAD);
	printf("Execution Time : %lfms\n", timeDiff*1000);
	printf("pi=%.24lf\n", pi);
}