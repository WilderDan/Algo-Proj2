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
 
// For use in random generation:
#define MIN_VAL             1
#define MAX_VAL             9999

#define SIZE_DEMO           100

#define FILE_BIGGER         "bigger_file"
#define SIZE_BIGGER         20

#define FILE_SMALLER        "smaller_file"
#define SIZE_SMALLER        10
 
const int N_SIZES[] = {50, 250, 1250};
const int M_SIZES[] = {25, 50, 100};

void demoMergeSort();
void demoFileMerge();
void mergeArrays(int dest[], int srcA[], int sizeA, int srcB[], int sizeB);
 
int main() {
    
    srand(time(NULL));
    
    demoMergeSort();
    demoFileMerge();

    return 0;
 }
 
void demoMergeSort() {
    int arr[SIZE_DEMO];
    
    printf("%d Unsorted Elements:\n", SIZE_DEMO);
    randomInitialize(arr, SIZE_DEMO, MIN_VAL, MAX_VAL);
    fprintArray(stdout, arr, SIZE_DEMO);
     
    printf("\nMerge Sort:\n");
    mergeSort(arr, 0, SIZE_DEMO - 1);
    fprintArray(stdout, arr, SIZE_DEMO);
 }
 
void demoFileMerge() {
    const int SIZE_MERGE = SIZE_BIGGER + SIZE_SMALLER;
    
    int A[SIZE_BIGGER];
    int B[SIZE_SMALLER];
    int C[SIZE_MERGE];
    
    FILE *fpBig;
    FILE *fpSmall;
    
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
    
    mergeArrays(C, A, SIZE_BIGGER, B, SIZE_SMALLER);
    
    printf("\nMerged file:\n");
    fprintArray(stdout, C, SIZE_MERGE);
 }
 
void mergeArrays(int dest[], int srcA[], int sizeA, int srcB[], int sizeB) {
    int sizeDest = sizeA + sizeB;
    
    copyArray(dest, srcA, sizeA, 0);
    copyArray(dest, srcB, sizeB, sizeA);
    merge(dest, 0, sizeA - 1, sizeDest - 1);
 }