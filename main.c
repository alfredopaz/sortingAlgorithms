#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "sorting.h"

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
  double deltaTimeI, deltaTimeM;
  int minArraySize = atoi(argv[1]);
  int maxArraySize = atoi(argv[2]);
  int incr = atoi(argv[3]);

  for(arraySize = minArraySize; 
      arraySize < maxArraySize; 
      arraySize += incr){
    a = malloc(sizeof(int) * arraySize);
    fillArray(arraySize, a);

    deltaTimeI = gettingSortingTime(arraySize, a, insertionSort);
    deltaTimeM = gettingSortingTime(arraySize, a, mergeSort);

    printf("%d %f %f\n", arraySize, deltaTimeI, deltaTimeM);

    free(a);
  }

}
