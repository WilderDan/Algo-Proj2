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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// PARAMETERS 

#define MIN_VAL             1
#define MAX_VAL             9999
#define SIZE_DEMO           100
#define FILE_BIGGER         "bigger_file"
#define SIZE_BIGGER         20
#define FILE_SMALLER        "smaller_file"
#define SIZE_SMALLER        10
#define NUM_TRIALS          10

const int N_SIZES[] = {1000, 10000, 100000};
const int M_SIZES[] = {25, 50, 100};

void demoMergeSort();
void demoFileMerge();
void sortThenMerge(int dest[], int srcA[], int sizeA, int srcB[], int sizeB);
void appendThenSort(int dest[], int srcA[], int sizeA, int srcB[], int sizeB);
void experiment(char *, void (*)(int [], int [], int, int [], int) );
 
int main() {
    
    srand(time(NULL));
    
    demoMergeSort();
    demoFileMerge();
    
    experiment("Sort then Merge", sortThenMerge);
    experiment("Append then Sort", appendThenSort);

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
    
    sortThenMerge(C, A, SIZE_BIGGER, B, SIZE_SMALLER);
    
    printf("\nSorted smaller file:\n");
    fprintArray(stdout, B, SIZE_SMALLER);
    
    printf("\nMerged file:\n");
    fprintArray(stdout, C, SIZE_MERGE);
}
 
void sortThenMerge(int dest[], int srcA[], int sizeA, int srcB[], int sizeB) {
/*  ASSUME srcA is sorted. Sort srcB. Merge arrays into dest.
 */
    int sizeDest = sizeA + sizeB;
    
    mergeSort(srcB, 0, sizeB - 1);
    
    copyArray(dest, srcA, sizeA, 0);
    copyArray(dest, srcB, sizeB, sizeA);
    merge(dest, 0, sizeA - 1, sizeDest - 1);
}

void appendThenSort(int dest[], int srcA[], int sizeA, int srcB[], int sizeB) {
    int sizeDest = sizeA + sizeB;
    
    copyArray(dest, srcA, sizeA, 0);
    copyArray(dest, srcB, sizeB, sizeA);
    mergeSort(dest, 0, sizeDest - 1);
}
 
void experiment(char *tag, void (*func)(int [], int [], int, int [], int)) {
    int numN = sizeof(N_SIZES)/sizeof(N_SIZES[0]);
    int numM = sizeof(M_SIZES)/sizeof(M_SIZES[0]);
    int sizeDest;
    int i, j, k;
     
    int *arrN[NUM_TRIALS];
    int *arrM[NUM_TRIALS];
    int *arrDest[NUM_TRIALS];
     
    clock_t start, end;
    double average;
    
    printf("\nExperiment: %s\n", tag);

    // For each size combination
    for (i = 0; i < numN; ++i) {
        for (j = 0; j < numM; ++j) {
             
            // Allocate and initialize sample arrays
            for (k = 0; k < NUM_TRIALS; ++k) {
                arrN[k] = (int *) malloc(N_SIZES[i] * sizeof(int));
                arrM[k] = (int *) malloc(M_SIZES[j] * sizeof(int));
                
                sizeDest = N_SIZES[i] + M_SIZES[j];
                arrDest[k] = (int *) malloc(sizeDest * sizeof(int));
                
                // Experiment assumes array of size N is sorted
                randomInitialize(arrN[k], N_SIZES[i], MIN_VAL, MAX_VAL);
                mergeSort(arrN[k], 0, N_SIZES[i] - 1);
                
                randomInitialize(arrM[k], M_SIZES[j], MIN_VAL, MAX_VAL);
            }
             
            // Start timer
            start = clock();
             
            // Run test NUM_TRIALS times
            for (k = 0; k < NUM_TRIALS; ++k) {
                (*func)(arrDest[k], arrN[k], N_SIZES[i], arrM[k], M_SIZES[j]);
            }
             
            // Stop timer and get average time   
            end = clock();
            average = ((end - start) / (double) CLOCKS_PER_SEC) / NUM_TRIALS;  
            
            // Free memory
            for (k = 0; k < NUM_TRIALS; ++k) {
                free(arrN[k]);
                free(arrM[k]);
                free(arrDest[k]);
            }
            
            // Print results
            printf("\n\tArray sizes %d and %d:\n", N_SIZES[i], M_SIZES[j]);
            printf("\t\tAverage CPU execution time: %lf msecs\n", average*1000);
        }
    }
}