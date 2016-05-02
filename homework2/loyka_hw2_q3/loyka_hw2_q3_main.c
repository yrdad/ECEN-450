//Kyle Loyka
//ECEN 449 - 503
//Homework 2
//Question 3

#define true  1
#define false 0

#include<stdlib.h>
#include<stdio.h>
#include "loyka_hw2_q3_prime.h"

int array1[10] = {1,9,31,2,7,5,11,4,10,12};
int array2[8]  = {3,1,23,8,7,6,2,10};

int main(void){
  int* prime_array = prime(array1, 10);
  int i;
  printf("Array: {1,9,31,2,7,5,11,4,10,12}\n");
  for (i = 0; i < 10; ++i){
    printf("%d\n",prime_array[i]);
  }
  free(prime_array);
  printf("--------------------------------\n\n");


  int* prime_array2 = prime(array2, 8);
  printf("Array: {3,1,23,8,7,6,2,10}\n");
  for (i = 0; i < 8; ++i){
    printf("%d\n",prime_array2[i]);
  }
  free(prime_array2);
  printf("--------------------------------\n\n");
  return 0;
}
