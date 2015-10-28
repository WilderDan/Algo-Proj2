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
 
#define DEMO_SIZE   20
#define MIN_VAL     1
#define MAX_VAL     40

int main() {
    int arr[DEMO_SIZE];
  
    printf("Heap sort demo...\n");
    randomInitialize(arr, DEMO_SIZE, MIN_VAL, MAX_VAL);
    fprintArray(stdout, arr, DEMO_SIZE);
    printf("\n");
    
    heapSort(arr, DEMO_SIZE);
    fprintArray(stdout, arr, DEMO_SIZE);
    printf("\n");
        
    return 0;
}