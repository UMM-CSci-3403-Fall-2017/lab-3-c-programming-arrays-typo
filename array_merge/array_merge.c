#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "../mergesort/mergesort.c"


int* array_merge(int num_arrays, int* sizes, int** values){
if(num_arrays == 0){ //handles empty array
  int* emptyArray = (int*)calloc(1, sizeof(int));
  return emptyArray;
}

int potentialSize = 0;
  for(int i = 0; i < num_arrays; i++){ // we don't know  the size so we have compute the potential one
    potentialSize += sizes[i];
  }
  printf("Potential size %d", potentialSize);


//This is array will contain every element
int* potentialArray = (int*)calloc(potentialSize, sizeof(potentialSize));
int start = 0;
  for(int i = 0; i < num_arrays;i++){
    for(int j = 0; j < sizes[i]; j++){
      potentialArray[start] = values[i][j];
      start++;
    }
  }

// This array will contain unique elements
int* uniqueVals = (int*)calloc(potentialSize, sizeof(potentialSize));
int x;
int numberOfUnique = 0;
int existAlready = 0;
int size1 = 0;
int startPoint = 0;
int zeroHandler = 0; // We need to handle zeroes because calloc will initiliaze everuthing as zero when called
for(int i = 0; i < potentialSize; i++){
x = potentialArray[i];
if(x==0){ //if holds then the original array contains zero
zeroHandler = 1;
}
  for(int j = 0; j <= size1; j++){
    if(uniqueVals[j] == x){ //If this condition holds then we skip this elements since it's already in our unique array
      existAlready = 1;
    }
  }

if(existAlready < 1){ // if this element is not in the unique array yet we will put it in
      numberOfUnique++;
      uniqueVals[startPoint] = x;
      startPoint++;
      size1++;
}
  existAlready = 0;
}

if(zeroHandler > 0){
 numberOfUnique++; // So we don't loose our original zero
}

free(potentialArray);

mergesort(numberOfUnique, uniqueVals);

int* resultArray;
resultArray = (int*)calloc(numberOfUnique+1, sizeof(numberOfUnique));
resultArray[0] = numberOfUnique;
for(int i = 0; i < numberOfUnique; i++){
  resultArray[i+1] = uniqueVals[i];
}
free(uniqueVals);

return resultArray; // will containn the number of elements in the array and the sorted array
}
