#ifndef PRIME_C
#define PRIME_C

#define true  1
#define false 0

#include "loyka_hw2_q3_swap.h"
#include "loyka_hw2_q3_sort_array.h"
#include "loyka_hw2_q3_prime.h"
#include<stdlib.h>

/* function to determine if a number is prime.
    returns 1 if number is prime
    returns 0 if number isn't prime */
int isPrime(int N){
  int i;
  int val = true;
  if (N < 2) return false; // all numbers less than 2 are not prime
  for(i = 2; i < N; ++i){
    if ( (N != 1) && (N != 0) ){ // 1 and 0 aren't prime
      if (N%i == 0) val = false;
    }
  }
  return val;
}


/* finds prime numbers in array, size M, and returns pointer to sorted array
   of these prime numbers */
int* prime(int* B, int M){

  /* sort the input array */
  sort_array(B,M);

  /* make a new array to store the prime numbers */
  int* tmp_array = calloc(M,sizeof(int));
  int i;

  /* find primes and populate the temp array */
  int prime_counter = 0; // keep track of the number of prime numbers
  for(i = 0; i < M; ++i){ // iterating through passed array
    if (isPrime(B[i])) {
      tmp_array[i] = B[i];
      ++prime_counter;
    }
  }

  return tmp_array;

  /* The returned array will consist of zeros or prime numbers. Zeros will be
     in indexes that contain NON-prime numbers. I could return an array with
     only the prime numbers, but then you have to figure out what your new array
     size is, and convey this information to the user (or other programmer).
     It's just not worth the trouble.

     You could parse the returned array. All non-zero values are prime numbers
  */
}


#endif
