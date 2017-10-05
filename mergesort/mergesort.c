
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mergesort.h"

//Took this from Nic's implementation
// The link: https://gist.github.umn.edu/mcphee/83e9818b21ef9cb3cde4

void mergeRanges(int* values, int startIndex, int midPoint, int endIndex);
int needsSorting(int rangeSize);
void mergesortRange(int* values, int startIndex, int endIndex);


void mergesort(int size, int* values){
mergesortRange(values, 0, size);
}

void mergesortRange(int* values, int startIndex, int endIndex){
int rangeSize = endIndex - startIndex;
 if(needsSorting(rangeSize)){
  int midPoint = (startIndex + endIndex)/2;
  mergesortRange(values, startIndex, midPoint);
  mergesortRange(values, midPoint, endIndex);
  mergeRanges(values, startIndex, midPoint, endIndex);
 }
}


void mergeRanges(int* values, int startIndex, int midPoint, int endIndex){
    int rangeSize = endIndex - startIndex;
    int* destination;
    destination = (int*)calloc(rangeSize, sizeof(int)); //Changed it so we can allocate memory from heap
    int firstIndex = startIndex;
    int secondIndex = midPoint;
    int copyIndex = 0;
    while (firstIndex < midPoint && secondIndex < endIndex) {
      if (values[firstIndex] < values[secondIndex]) {
        destination[copyIndex] = values[firstIndex];
        ++firstIndex;
      } else {
        destination[copyIndex] = values[secondIndex];
        ++secondIndex;
      }
      ++copyIndex;
    }
    while (firstIndex < midPoint) {
      destination[copyIndex] = values[firstIndex];
      ++copyIndex;
      ++firstIndex;
    }
    while (secondIndex < endIndex) {
      destination[copyIndex] = values[secondIndex];
      ++copyIndex;
      ++secondIndex;
    }
    for (int i = 0; i < rangeSize; ++i) {
      values[i + startIndex] = destination[i];
    }

    free(destination);
}
 
 int needsSorting(int rangeSize){
  return rangeSize >=2;
 }
