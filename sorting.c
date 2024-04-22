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

void merge(int a[], int p, int q, int r) {
  int i, j, k;
  int nl = q - p + 1;
  int nr = r - q;

  int la[nl + 1], ra[nr + 1];

  for(i = 0; i < nl - 1; i++)
    la[i] = a[p + i];

  for(j = 0; j < nr - 1; j++)
    ra[j] = a[q + j + 1];

  i = 0;
  j = 0;
  k = p;

  while(i < nl && j < nr){
    if(la[i] <= ra[j]){
      a[k] = la[i];
      i++;
    }else{
      a[k] = ra[j];
      j++;
    }
    k++;
  }

  while (i < nl) {
    a[k] = la[i];
    i++;
    k++;
  }

  while (j < nr) {
    a[k] = ra[j];
    j++;
    k++;
  }
}

void mSort(int a[], int p, int r) {
  if(p >= r)
    return;
  int q = (p + r) / 2;
  mSort(a, p, q);
  mSort(a, q + 1, r);
  merge(a, p, q, r);
}

void mergeSort(int n, int* a){
  mSort(a, 0, n);
}

int testSortAsc(int s, int f, int* a){
  if(f > s) return 1;
  if(f - s <= 1) return 1;
  for(int i = s; i < f; i++)
    if(a[i - 1] > a[i]) return 0;
  return 1;
}

