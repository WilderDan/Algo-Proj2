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

#include "sort_algorithms.h"
#include <math.h>
#include <limits.h>

void swap(int *, int *);
void merge(int *arr, int lo, int mid, int hi);
int  partition(int *arr, int lo, int hi);

void mergeSort(int *arr, int lo, int hi) {
    
    int mid;
    
    if (lo < hi) {
        mid = floor( (lo + hi) / 2 );
        
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);
        
        merge(arr, lo, mid, hi);
    }
}

void merge(int *arr, int lo, int mid, int hi) {

    int i, j, k;
    int numL = mid - lo + 1;
    int numR = hi - mid;
    
    int left[numL + 1];
    int right[numR + 1];

    // Initialize new subarrays    
    for (i = 0; i < numL; ++i)
        left[i] = arr[lo + i];
        
    for (j = 0; j < numR; ++j)
        right[j] = arr[mid + j + 1];
        
    // Sentinel Values
    left[numL] = INT_MAX;
    right[numR] = INT_MAX;
    
    i = j = 0;
    for (k = lo; k <= hi; ++k) {
        
        if (left[i] < right[j]) {
            arr[k] = left[i];
            ++i;
        }
        
        else {
            arr[k] = right[j];
            ++j;
        }
    }
}

void quickSort(int *arr, int lo, int hi) {
    
    int p;
    
    if (lo < hi) {
        p = partition(arr, lo, hi);
        quickSort(arr, lo, p - 1);
        quickSort(arr, p + 1, hi);
    }
}

int partition(int *arr, int lo, int hi) {
    
    int pivot = arr[hi];
    int i = lo;
    int j;
    
    for(j = lo; j < hi; ++j) {
        if (arr[j] <= pivot) {
            swap(arr + i, arr + j);
            ++i;
        }
    }
    
    swap(arr + i, arr + hi);
    return i;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}