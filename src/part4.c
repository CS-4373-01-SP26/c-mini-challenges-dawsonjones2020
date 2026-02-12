#include <stdio.h>
#include <time.h>
#include <math.h>

void time_star(){
    int testnum = 10;
    // start clock before computation - got timing code from GPT
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); 
    for (int i = 0; i < 10; i++){
        testnum *= 2;
    }
    clock_gettime(CLOCK_MONOTONIC, &end); // end clock after computation
    long elapsed_nanoseconds = end.tv_nsec  - start.tv_nsec;
    printf("10 * operations took %ld nanoseconds\n", elapsed_nanoseconds);
}

void time_slash(){
    int testnum = 10000;
    // start clock before computation - got timing code from GPT
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); 
    for (int i = 0; i < 10; i++){
        testnum /= 2;
    }
    clock_gettime(CLOCK_MONOTONIC, &end); // end clock after computation
    long elapsed_nanoseconds = end.tv_nsec  - start.tv_nsec;
    printf("10 / operations took %ld nanoseconds\n", elapsed_nanoseconds);
}

void time_sqrt(){
    int testnum = 8192;
    // start clock before computation - got timing code from GPT
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); 
    for (int i = 0; i < 10; i++){
        testnum = sqrt(testnum);
    }
    clock_gettime(CLOCK_MONOTONIC, &end); // end clock after computation
    long elapsed_nanoseconds = end.tv_nsec  - start.tv_nsec;
    printf("10 sqrt operations took %ld nanoseconds\n", elapsed_nanoseconds);
}

void time_sin(){
    int testnum = 10;
    // start clock before computation - got timing code from GPT
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); 
    for (int i = 0; i < 10; i++){
        testnum = sin(testnum);
    }
    clock_gettime(CLOCK_MONOTONIC, &end); // end clock after computation
    long elapsed_nanoseconds = end.tv_nsec  - start.tv_nsec;
    printf("10 sin operations took %ld nanoseconds\n", elapsed_nanoseconds);
}

// Compare the speed of *,/,sqrt, sin operations/functions.
int main(){
    time_star();
    time_slash();
    time_sqrt();
    time_sin();
    return 0;
}