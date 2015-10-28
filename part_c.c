/*  Dan Wilder
 *
 *  University of Missouri - St. Louis
 *  CS 3130 - Design & Analysis of Algorithms
 *  Galina Piatnitskiaia (instructor)
 *  Project #2
 *
 *  part_c.c
 *      Program satisfying part C of project #2. 
 */
 
#include "array_utilities.h"
#include "sort_algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define DEMO_SIZE   50
#define MIN_VAL     1
#define MAX_VAL     9999
#define NUM_TRIALS  10

const int SIZES[] = {10000, 100000, 1000000};

void timeConstruction();
void timeHeapSort();

int main() {
    int arr[DEMO_SIZE];
  
    srand(time(NULL));
    
    printf("%d Unsorted elements\n", DEMO_SIZE);
    randomInitialize(arr, DEMO_SIZE, MIN_VAL, MAX_VAL);
    fprintArray(stdout, arr, DEMO_SIZE);
    
    printf("\nApplying heapSort...\n");
    heapSort(arr, DEMO_SIZE);
    fprintArray(stdout, arr, DEMO_SIZE);
    
    timeConstruction();
    timeHeapSort();
        
    return 0;
}

void timeConstruction() {
    int *A[NUM_TRIALS];
    int numSizes = sizeof(SIZES)/sizeof(SIZES[0]);
    int i, k;
    
    clock_t start, end;
    double average;
    
    printf("\nHeap construction (bottom-up) times...\n");
    
    // For each size
    for(i = 0; i < numSizes; ++i) {
        
        // Allocate
        for (k = 0; k < NUM_TRIALS; ++k) {
            A[k] = (int *) malloc(SIZES[i] * sizeof(int));
            randomInitialize(A[k], SIZES[i], MIN_VAL, MAX_VAL);
        }        
        
        // Calculate time
        start = clock();
        for (k = 0; k < NUM_TRIALS; ++k) {
            buildMaxHeap(A[k], SIZES[i]);
        }
        end = clock();
        
        average = ((end - start) / (double) CLOCKS_PER_SEC) / NUM_TRIALS;
        
        // Free memory
        for (k = 0; k < NUM_TRIALS; ++k)
            free(A[k]);
              
        // Print results
        printf("\n\tArray size %d:\n", SIZES[i]);
        printf("\t\tAverage CPU execution time: %lf msecs\n", average*1000);
    }
}

void timeHeapSort() {
    int *A[NUM_TRIALS];
    int numSizes = sizeof(SIZES)/sizeof(SIZES[0]);
    int i, k;
    
    clock_t start, end;
    double average;
    
    printf("\nHeapsort times...\n");
    
    // For each size
    for(i = 0; i < numSizes; ++i) {
        
        // Allocate
        for (k = 0; k < NUM_TRIALS; ++k) {
            A[k] = (int *) malloc(SIZES[i] * sizeof(int));
            randomInitialize(A[k], SIZES[i], MIN_VAL, MAX_VAL);
        }        
        
        // Calculate time
        start = clock();
        for (k = 0; k < NUM_TRIALS; ++k) {
            heapSort(A[k], SIZES[i]);
        }
        end = clock();
        
        average = ((end - start) / (double) CLOCKS_PER_SEC) / NUM_TRIALS;
        
        // Free memory
        for (k = 0; k < NUM_TRIALS; ++k)
            free(A[k]);
              
        // Print results
        printf("\n\tArray size %d:\n", SIZES[i]);
        printf("\t\tAverage CPU execution time: %lf msecs\n", average*1000);
    }
}