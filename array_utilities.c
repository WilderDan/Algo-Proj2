/*  Dan Wilder
 *
 *  University of Missouri - St. Louis
 *  CS 3130 - Design & Analysis of Algorithms
 *  Galina Piatnitskiaia (instructor)
 *  Project #2
 *
 *  array_utilities.c
 *      Implements some functions for working with arrays.
 */

#include <stdio.h>
#include <stdlib.h>
#include "array_utilities.h"

void fprintArray(FILE *stream, int arr[], int size) {
/* Print 10 values per line with aligned columns
 */
    int i;

    for (i=0; i < size; i++) {
        fprintf(stream, "%5d ", arr[i]);
        if ((i+1)%10 == 0)
            fprintf(stream, "\n");
    }
}

void randomInitialize(int arr[], int size, int minVal, int maxVal) {
/* Initialize arr[0..size-1] to random int in interval [minVal, maxVal]
 * srand() should be called in application program ONCE prior to calling this
 */
    int i, randomInt;
   
    for (i = 0; i < size; i++) {
        randomInt = (rand() % maxVal-minVal) + minVal;
        arr[i] = randomInt;
    }
}

void copyArray(int dest[], int source[], int size, int start) {
/* Copy the first size elements from source into dest[start...start + size - 1]
 */
    int i, j;
    for (i = start, j = 0; i < start + size; ++i, ++j)
        dest[i] = source[j];
}

void readArrayFile(FILE *stream, int arr[], int size) {
    int i, read;

    for (i = 0; i < size; ++i) {
        if (fscanf(stream, "%d", &read) == EOF) 
            break;
        arr[i] = read;
    }
}