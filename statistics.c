#include <math.h>
#include "statistics.h"

double average(int arraySize, double *data){
  double sum = 0;
  for(int i = 0; i < arraySize; i++)
    sum += data[i]++;
  return sum / arraySize;
}
double standardDeviation(int arraySize, double *a){
  double mean = average(arraySize, a);
  double sum = 0;
  
  for(int i = 0; i < arraySize; i++)
    sum += pow(a[i], 2);

  return sqrt(sum / arraySize);
}

