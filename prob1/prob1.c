#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int isPrime(int x) {
    int i;
    if (x <= 1) {
        return 0;
    }
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}


// schedule type, argv[1]
// 1(static), 2(dynamic), 3(static, 10), 4(dynamic,10)

// number of thread, argv[2]

int NUM_THREAD;
int SCHEDULE;
int START;
int END;

int main(int argc, char* argv[]) {
    SCHEDULE = atoi(argv[1]);
    NUM_THREAD = atoi(argv[2]);
    START = 1;
    END = 200000;

    int count = 0;
    int i;
    
    double start_time, end_time;

    omp_set_num_threads(NUM_THREAD);

    start_time = omp_get_wtime();

    switch (SCHEDULE) {
    case 1:
    #pragma omp parallel for reduction(+:count) schedule(static)
        for (i = 1; i <= END; i++) {
            if (isPrime(i)) {
                count += 1;
            }
        }
        break;
    case 2:
    #pragma omp parallel for reduction(+:count) schedule(dynamic)
        for (i = 1; i <= END; i++) {
            if (isPrime(i)) {
                count += 1;
            }
        }
        break;
    case 3:
    #pragma omp parallel for reduction(+:count) schedule(static, 10)
        for (i = 1; i <= END; i++) {
            if (isPrime(i)) {
                count += 1;
            }
        }
        break;
    case 4:
    #pragma omp parallel for reduction(+:count) schedule(dynamic, 10)
        for (i = 1; i <= END; i++) {
            if (isPrime(i)) {
                count += 1;
            }
        }
        break;
    default:
        printf("Wrong option\n");
        return 1;
    }

    end_time = omp_get_wtime();

    printf("The number of prime numbers (1~200000) : %d\n", count);
    printf("Time elapsed : %lfms\n", (end_time - start_time)*1000.0);
    printf("Schedule option : %d\n", SCHEDULE);
    printf("Number of threads : %d\n", NUM_THREAD);
}