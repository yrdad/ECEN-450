//Kyle Loyka
//ECEN 449 - 503
//Homework 2
//Question 4

#define true  1
#define false 0

/*---- Given Arrays ----*/
int A1[4] = {1,3,9,20};
int B1[4] = {2,4,10,16};

int A2[1] = {0};
int B2[2] = {0,0};

int A3[6] = {2,2,2,3,3,3};
int B3[3] = {-1,-1,-1};
/*-----------------------*/


#include<stdlib.h>
#include<stdio.h>

/* Given two sorted arrays of integers A and B, A and B are merged into one
   larger sorted array, M, without duplicates. The function returns the size
   of M */
int merge(int* A, int* B, int A_size, int B_size, int* M){

  int A_index = 0;
  int B_index = 0;
  int M_index = 0;

  int aIsAtEnd = false;
  int bIsAtEnd = false;

  int buffer;

  /* Merging both arrays */
  while(1){
    /* if element A is less than element B _OR_ if we are at the end of
       B array, write A's element to M    */
    if ( (A[A_index] < B[B_index]) || bIsAtEnd ){
        buffer = A[A_index];
        ++A_index;
    }
    /* if element B is less than element A _OR_ if we are at the end of
       A array, we write B's element to M   */
    else if ( (A[A_index] > B[B_index]) || aIsAtEnd ){
          buffer = B[B_index];
          ++B_index;
    }
    /* case when element of A and B are same */
    else {
        buffer = B[B_index];
        ++B_index;
        ++A_index;
      }
    /* ensuring no duplicate values are written to M */
    if(M[M_index-1] != buffer){
      M[M_index] = buffer;
      ++M_index;
    }
    /* Check to see if at end of either array */
    if(A_index == A_size) aIsAtEnd = true;
    if(B_index == B_size) bIsAtEnd = true;

    /* if we reach the end of both arrays A and B, we are done populating
       M array. */
    if(aIsAtEnd && bIsAtEnd) break;
  }
  return M_index;
}


/* Function to print array contents in a easy to read format */
void printArray(int* A, int A_size){
  printf("{");
  int i;
  for(i = 0; i < (A_size-1); ++i){
    printf("%d,",A[i]);
  }
  printf("%d} \n",A[A_size-1]);
}

int main(void){
  int* M;
  int M_size;

  // (a)
  printArray(A1,4);
  printArray(B1,4);
  printf("Merged Array: ");
  M = malloc((4+4)*sizeof(int)); //max size is the size of A and B combined
  M_size = merge(A1,B1,4,4,M);
  printArray(M,M_size);
  free(M);  // gotta free the allocated memory

  // (b)
  printArray(A2,1);
  printArray(B2,2);
  printf("Merged Array: ");
  M = malloc((1+2)*sizeof(int)); //max size is the size of A and B combined
  M_size = merge(A2,B2,1,2,M);
  printArray(M,M_size);
  free(M);  // gotta free the allocated memory

  // (c)
  printArray(A3,6);
  printArray(B3,3);
  printf("Merged Array: ");
  M = malloc((6+3)*sizeof(int)); //max size is the size of A and B combined
  M_size = merge(A3,B3,6,3,M);
  printArray(M,M_size);
  free(M);  // gotta free the allocated memory

return 0;
}
