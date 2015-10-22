/*  Dan Wilder
 *
 *  University of Missouri - St. Louis
 *  CS 3130 - Design & Analysis of Algorithms
 *  Galina Piatnitskiaia (instructor)
 *  Project #2
 *
 *  part_b.c
 *      Program satisfying part B of project #2. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_utilities.h"
#include "sort_algorithms.h"

#define MIN_VAL             1
#define MAX_VAL             9999
#define DEMO_SIZE           50
#define NUM_TRIALS          10

const int SIZES[] = {1000, 10000, 100000};

int basicSelect(int *arr, int lo, int hi);
int medianOfThreeSelect(int *arr, int lo, int hi);
int medianOfFiveSelect(int *arr, int lo, int hi);
void experiment(char *tag, int (*select)(int *, int, int));

int main() {
    int arr[DEMO_SIZE];

    srand(time(NULL));
    
    printf("Randomly Initializing arrays.\n");
    printf("Applying Quick Sort using...\n");
    
    printf("\n 1) Basic Selection:\n");
    randomInitialize(arr, DEMO_SIZE, MIN_VAL, MAX_VAL);
    quickSort(arr, 0, DEMO_SIZE - 1, basicSelect);
    fprintArray(stdout, arr, DEMO_SIZE);

    printf("\n 2) Median of 3 Selection:\n");
    randomInitialize(arr, DEMO_SIZE, MIN_VAL, MAX_VAL);
    quickSort(arr, 0, DEMO_SIZE - 1, medianOfThreeSelect);
    fprintArray(stdout, arr, DEMO_SIZE);

    printf("\n 3) Median of 5 Selection:\n");
    randomInitialize(arr, DEMO_SIZE, MIN_VAL, MAX_VAL);
    quickSort(arr, 0, DEMO_SIZE - 1, medianOfFiveSelect);
    fprintArray(stdout, arr, DEMO_SIZE);
    
    experiment("Basic Selection", basicSelect);
    experiment("Median of Three", medianOfThreeSelect);
    experiment("Median of Five", medianOfFiveSelect);
    
    return 0;
}

int basicSelect(int *arr, int lo, int hi) {
    return hi;
}

int medianOfThreeSelect(int *arr, int lo, int hi) {
    int mid = (hi + lo) / 2;
    
    int space[3] = {arr[lo], arr[mid], arr[hi]};
    insertionSort(space, 3);
    
    return space[1] == arr[lo] ? lo : (space[1] == arr[mid] ? mid : hi); 
}

int medianOfFiveSelect(int *arr, int lo, int hi) {
    int space[5];
    int in[5];
    int i;
   
    for (i = 0; i < 5; ++i) { 
        in[i] = (rand() % (hi-lo)) + lo;
        space[i] = arr[in[i]];
    }
    
    insertionSort(space, 5);
    
    for (i = 0; i < 5; ++i)
        if (space[2] == arr[in[i]])
            return in[i];
            
    return -1;
}

void experiment(char *tag, int (*select)(int *, int, int)) {
    int *A[NUM_TRIALS];
    int numSizes = sizeof(SIZES)/sizeof(SIZES[0]);
    int i, k;
    
    clock_t start, end;
    double average;
    
    printf("\nSelection method = %s", tag);
    
    for(i = 0; i < numSizes; ++i) {
        
        // Allocate
        for (k = 0; k < NUM_TRIALS; ++k) {
            A[k] = (int *) malloc(SIZES[i] * sizeof(int));
            randomInitialize(A[k], SIZES[i], MIN_VAL, MAX_VAL);
        }        
        
        start = clock();
        
        for (k = 0; k < NUM_TRIALS; ++k) {
            quickSort(A[k], 0, SIZES[i] - 1, select);
        }
            
        // Stop timer and get average time   
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