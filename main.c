#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "sorting.h"


int main(int argc, char* argv[]){
  int arraySize;
  int* a;
  struct timespec start, end;
  double deltaTimeI, deltaTimeM;
  int minArraySize = atoi(argv[1]);
  int maxArraySize = atoi(argv[2]);
  int incr = atoi(argv[3]);

  for(arraySize = minArraySize; 
      arraySize < maxArraySize; 
      arraySize += incr){
    a = malloc(sizeof(int) * arraySize);
    fillArray(arraySize, a);

    //Insertion Sort
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    insertionSort(arraySize, a);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    assert(testSortAsc(0, arraySize, a));
    
    deltaTimeI = (end.tv_sec - start.tv_sec) + 
                (double) (end.tv_nsec - start.tv_nsec) / 1e9;

    free(a);

    //Merge Sort
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    mergeSort(arraySize, a);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    assert(testSortAsc(0, arraySize, a));

    deltaTimeM = (end.tv_sec - start.tv_sec) + 
                (double) (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("%d %f %f\n", arraySize, deltaTimeI, deltaTimeM);

  }

}
