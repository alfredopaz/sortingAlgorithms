#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"


int main(int argc, char* argv[]){
  int arraySize;
  int* a;
  struct timespec start, end;
  double deltaTime;
  int minArraySize = atoi(argv[1]);
  int maxArraySize = atoi(argv[2]);
  int incr = atoi(argv[3]);

  for(arraySize = minArraySize; 
      arraySize < maxArraySize; 
      arraySize += incr){
    a = malloc(sizeof(int) * arraySize);
    fillArray(arraySize, a);

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    insertionSort(arraySize, a);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    deltaTime = (end.tv_sec - start.tv_sec) + 
                (double) (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("%d %f\n", arraySize, deltaTime);

    free(a);
  }

}
