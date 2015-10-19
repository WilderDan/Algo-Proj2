/*  Dan Wilder
 *
 *  University of Missouri - St. Louis
 *  CS 3130 - Design & Analysis of Algorithms
 *  Galina Piatnitskiaia (instructor)
 *  Project #2
 *
 *  part_a.c
 *      Program satisfying part A of project #2.
 */
 
#include "array_utilities.h"
#include "sort_algorithms.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
 
#define MIN_VAL             1
#define MAX_VAL             9999

#define FILE_BIGGER         "bigger_file"
#define SIZE_BIGGER         100

#define FILE_SMALLER        "smaller_file"
#define SIZE_SMALLER        10
 
const int N_SIZES[] = {50, 250, 1250};
const int M_SIZES[] = {25, 50, 100};
 
int main() {
    
    const int SIZE_MERGE = SIZE_BIGGER + SIZE_SMALLER;
    
    int A[SIZE_BIGGER];
    int B[SIZE_SMALLER];
    int C[SIZE_MERGE];
    
    FILE *fpBig;
    FILE *fpSmall;
    
    srand(time(NULL));

    // Show that mergeSort works
    printf("%d Unsorted Elements:\n", SIZE_BIGGER);
    randomInitialize(A, SIZE_BIGGER, MIN_VAL, MAX_VAL);
    fprintArray(stdout, A, SIZE_BIGGER);
     
    printf("\nmergeSort...\n");
    mergeSort(A, 0, SIZE_BIGGER - 1);
    fprintArray(stdout, A, SIZE_BIGGER);
    
    // Erase current contents
    memset(A, 0, SIZE_BIGGER * sizeof(int));
    
    fpBig = fopen(FILE_BIGGER, "r");
    if (fpBig == NULL) {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }
    
    // Retrieve larger array from file; ASSUME sorted
    readArrayFile(fpBig, A, SIZE_BIGGER);
    fclose(fpBig);
    
    fpSmall = fopen(FILE_SMALLER, "r");
    if (fpSmall == NULL) {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }
    
    // Retrieve smaller array from file; ASSUME unsorted
    readArrayFile(fpSmall, B, SIZE_SMALLER);
    fclose(fpSmall);
    
    printf("\nBigger sorted file contents:\n");
    fprintArray(stdout, A, SIZE_BIGGER);
    
    printf("\nSmaller unsorted file contents:\n");
    fprintArray(stdout, B, SIZE_SMALLER);
    
    printf("\nSorted smaller file:\n");
    mergeSort(B, 0, SIZE_SMALLER - 1);
    fprintArray(stdout, B, SIZE_SMALLER);
    
    // A & B are sorted so Merge
    copyArray(C, A, SIZE_BIGGER, 0);
    copyArray(C, B, SIZE_SMALLER, SIZE_BIGGER);
    merge(C, 0, SIZE_BIGGER - 1, SIZE_MERGE - 1);
    printf("\nMerged file:\n");
    fprintArray(stdout, C, SIZE_MERGE);
    
    return 0;
 }