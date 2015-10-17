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
 
 #define SIZE    30
 #define MIN_VAL 1
 #define MAX_VAL 9999
 
 int main() {
     
     int arr[SIZE];
     
     srand(time(NULL));

     printf("TESTING mergeSort...\n");
     randomInitialize(arr, SIZE, MIN_VAL, MAX_VAL);
     fprintArray(stdout, arr, SIZE);
     mergeSort(arr, 0, SIZE - 1);
     fprintArray(stdout, arr, SIZE);
     
     printf("TESTING quickSort...\n");
     randomInitialize(arr, SIZE, MIN_VAL, MAX_VAL);
     fprintArray(stdout, arr, SIZE);
     quickSort(arr, 0, SIZE - 1);
     fprintArray(stdout, arr, SIZE);
     
     return 0;
 }