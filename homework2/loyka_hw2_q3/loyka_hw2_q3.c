//Kyle Loyka
//ECEN 449 - 503
//Homework 2
//Question 3

#define true  1
#define false 0

#include<stdlib.h>
#include<stdio.h>

int array1[10] = {1,9,31,2,7,5,11,4,10,12};
int array2[8]  = {3,1,23,8,7,6,2,10};

/* function that swaps the values of 2 integers, a and b */
void swap(int* a, int* b){
  int temp = *b;
  *b = *a;
  *a = temp;
}


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

/* function to determine if a number is prime.
    returns 1 if number is prime
    returns 0 if number isn't prime */


int main(void){
  int* primes = prime(array1, 10);
  int i;
  for (i = 0; i < 10; ++i){
    printf("%d\n",primes[i]);
  }
  return 0;
}
