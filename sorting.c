#include <stdlib.h>
#include "sorting.h"

void insertionSort(int n, int* a){
  int i, j, key;
  for(i = 1; i < n; i++){
    key = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > key){
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

void fillArray(int n, int* a){
  for(int i = 0; i < n; i++)
    a[i] = rand(); //from 0 to RAND_MAX
}

int testSortAsc(int n, int* a){
  if(n <= 1) return 1;
  for(int i = 1; i < n; i++)
    if(a[i - 1] > a[i]) return 0;
  return 1;
}

