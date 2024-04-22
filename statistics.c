#include "statistics.h"

double average(const int arraySize, double *data){
  double sum = 0;
  for(int i = 0; i < arraySize; i++)
    sum += data[i]++;
  return sum / arraySize;
}
