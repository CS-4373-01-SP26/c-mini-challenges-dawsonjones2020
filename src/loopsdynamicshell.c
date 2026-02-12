#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int i,j;
  int n = 128;
  double sum;
  clock_t end, start;
  double *arr = malloc(n*n*sizeof(double));
  
// THIS FILLS THE MATRIX WITH NUMBERS
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      arr[i*n+j] = (double) rand()/RAND_MAX;

  sum = 0;

  // ROW MAJOR WORK
  start = clock(); // start time
  for (i = 0; i<n; i++) // iterate over rows 
    for (j = 0; j<n; j++) // iterate over columns 
      sum += arr[i*n + j];
  end = clock(); // end time
  // NOTE:  YOU'LL NEED TO PROVIDE MEANING TO end AND start
    printf("Row Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);

  sum = 0;

  // ADD YOUR COLUMN MAJOR WORK
  start = clock(); // start time
  for (i = 0; i<n; i++) // iterate over cols 
    for (j = 0; j<n; j++) // iterate over rows 
      sum += arr[j*n + i];
  end = clock(); // end time
  // NOTE:  YOU'LL NEED TO PROVIDE MEANING TO end AND start
    printf("Column Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);

  return 0;
}

