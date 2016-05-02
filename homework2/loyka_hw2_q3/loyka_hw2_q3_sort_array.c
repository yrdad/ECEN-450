#ifndef SORT_ARRAY_C
#define SORT_ARRAY_C

#include "loyka_hw2_q3_sort_array.h"
#include "loyka_hw2_q3_swap.h"

/* function that sorts an array, of length N, in ascending order. */
void sort_array(int* A, int N){
  /* using bubble sort algorithm */
  int swapped;  // treating swapped as boolean, 0 or 1
  int i;
  int j;

  for(i=1; i<N; ++i){
    swapped = 0;
    for(j = 0; j< N-i; ++j){
      if( A[j+1] < A[j] ){ // if next term is less than previous term, swap
        swap(A+j,A+j+1);
        swapped = 1;
      }
    }
    if(!swapped) break; // if no swap occurred, end the function
  }
}

#endif
