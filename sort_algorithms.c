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

void swap(int *x, int *y);
void maxHeapify(int *arr, int size, int i);
int partition(int *arr, int lo, int hi, int (*)(int *, int, int));
int leftChild(int i);
int rightChild(int i);

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

void mergeSort(int *arr, int lo, int hi) {
    int mid;
    
    if (lo < hi) {
        mid = floor( (lo + hi) / 2 );
        
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);
        
        merge(arr, lo, mid, hi);
    }
}

void quickSort(int *arr, int lo, int hi, int (*select)(int *, int, int)) {
    int p;
    
    if (lo < hi) {
        p = partition(arr, lo, hi, select);
        quickSort(arr, lo, p - 1, select);
        quickSort(arr, p + 1, hi, select);
    }
}

int partition(int *arr, int lo, int hi, int (*select)(int *, int, int)) {
    int pivot, pivotIndex;
    int i = lo;
    int j;
    
    pivotIndex = (*select)(arr, lo, hi);
    pivot = arr[pivotIndex];
    swap(arr + pivotIndex, arr + hi);
    
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

void insertionSort(int *arr, int size) {
    int i, j;
    
    for (i = 1; i < size; ++i) {
        j = i;
        
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(arr + j, arr + j -1);
            --j;
        }
    }
}

void heapSort(int *arr, int size) {
    int i;
    int length = size - 1;
    
    buildMaxHeap(arr, size);
    for (i  = length; i >= 1; --i) {
        swap(arr, arr + i);
        --length;
        maxHeapify(arr, length, 0);
    }
}

void buildMaxHeap(int *arr, int size) {
    int i;
    
    for (i = (size-1)/2; i >= 0; --i)
        maxHeapify(arr, size, i);
}

void maxHeapify(int *arr, int size, int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int largest;
    
    largest = (left < size && arr[left] > arr[i]) ? left : i;
    largest = (right < size && arr[right] > arr[largest]) ? right : largest;
    
    if (largest != i) {
        swap(arr + i, arr + largest);
        maxHeapify(arr, size, largest);
    }
        
}

int leftChild(int i) {
    return 2*i + 1;
}

int rightChild(int i) {
    return 2*i + 2;
}