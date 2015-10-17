/*  Dan Wilder
 *
 *  University of Missouri - St. Louis
 *  CS 3130 - Design & Analysis of Algorithms
 *  Galina Piatnitskiaia (instructor)
 *  Project #2
 *
 *  sort_algorithms.c
 *      Implements sorting algorithms.
 */

#include <math.h>
#include "sort_algorithms.h"

void merge(int *A, int p, int q, int r) {

    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int L[n1 + 1];
    int R[n2 + 1];

    // Initialize new subarrays    
    for (i = 0; i < n1; ++i)
        L[i] = A[p + i];
        
    for (j = 0; j < n2; ++j)
        R[j] = A[q + j + 1];
        
    // Sentinel Values
    L[n1] = MAX_VAL + 1;
    R[n2] = MAX_VAL + 1;
    
    
    // Combine
    i = j = 0;
    
    for (k = p; k <= r; ++k) {
        
        if (L[i] < R[j]) {
            A[k] = L[i];
            ++i;
        }
        
        else {
            A[k] = R[j];
            ++j;
        }
    }
}

void mergeSort(int *A, int p, int r) {
    
    int q;
    
    if (p < r) {
        q = floor( (p+r) / 2 );
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}