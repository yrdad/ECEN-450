#ifndef SWAP_C
#define SWAP_C

#include "loyka_hw2_q3_swap.h"

/* function that swaps the values of 2 integers, a and b */
void swap(int* a, int* b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

#endif
