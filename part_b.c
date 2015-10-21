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
#define DEMO_SIZE           100
#define NUM_TRIALS          10

int basicSelect(int *arr, int lo, int hi);
int medianOfThreeSelect(int *arr, int lo, int hi);
int medianOfFiveSelect(int *arr, int lo, int hi);

int main() {
    int arr[DEMO_SIZE];
    
    srand(time(NULL));
    
    printf("Basic Selection:\n");
    randomInitialize(arr, DEMO_SIZE, MIN_VAL, MAX_VAL);
    quickSort(arr, 0, DEMO_SIZE - 1, basicSelect);
    fprintArray(stdout, arr, DEMO_SIZE);

    printf("Median of 3 Selection:\n");
    randomInitialize(arr, DEMO_SIZE, MIN_VAL, MAX_VAL);
    quickSort(arr, 0, DEMO_SIZE - 1, medianOfThreeSelect);
    fprintArray(stdout, arr, DEMO_SIZE);

    printf("Median of 5 Selection:\n");
    randomInitialize(arr, DEMO_SIZE, MIN_VAL, MAX_VAL);
    quickSort(arr, 0, DEMO_SIZE - 1, medianOfFiveSelect);
    fprintArray(stdout, arr, DEMO_SIZE);
    
    return 0;
}

int basicSelect(int *arr, int lo, int hi) {
    return hi;
}

int medianOfThreeSelect(int *arr, int lo, int hi) {
    int mid = (hi + lo) / 2;
    
    int space[3] = {arr[lo], arr[mid], arr[hi]};
    mergeSort(space, 0, 2);
    
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

    mergeSort(space, 0, 4);
    
    for (i = 0; i < 5; ++i)
        if (space[2] == arr[in[i]])
            return in[i];
            
    return -1;
}