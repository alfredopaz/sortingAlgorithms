#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "sorting.h"
#include "statistics.h"

#define MAX_REPETITION 20

double gettingSortingTime(int arraySize, int o[], void (*sort)(int, int[])){
  int *a = malloc(sizeof(int) * arraySize);
  memcpy(a, o, sizeof(int) * arraySize);

  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  sort(arraySize, a);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  assert(testSortAsc(0, arraySize, a));

  double deltaTime = (end.tv_sec - start.tv_sec) + 
    (double) (end.tv_nsec - start.tv_nsec) / 1e9;
  free(a);
  return deltaTime;
}

int main(int argc, char* argv[]){
  int arraySize;
  int* a; 
  double data[2][MAX_REPETITION];
  double deltaTimeI, deltaTimeM;
  int minArraySize = atoi(argv[1]);
  int maxArraySize = atoi(argv[2]);
  int incr = atoi(argv[3]);


  for(arraySize = minArraySize; 
      arraySize < maxArraySize; 
      arraySize += incr){
    a = malloc(sizeof(int) * arraySize);
    
    for(int i = 0; i < MAX_REPETITION; i++){
      fillArray(arraySize, a);

      data[0][i] = gettingSortingTime(arraySize, a, insertionSort);
      data[1][i] = gettingSortingTime(arraySize, a, mergeSort);
    }

    deltaTimeI = average(MAX_REPETITION, data[0]);
    deltaTimeM = average(MAX_REPETITION, data[1]);

    printf("%d %f %f\n", arraySize, deltaTimeI, deltaTimeM);

    free(a);
  }
}
