/*  Dan Wilder
 *
 *  University of Missouri - St. Louis
 *  CS 3130 - Design & Analysis of Algorithms
 *  Galina Piatnitskiaia (instructor)
 *  Project #2
 *
 *  sort_algorithms.h
 *      Header file containing function declarations for sorting algorithms.        
 */

#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

    void merge(int *arr, int lo, int mid, int hi);
    void mergeSort(int *arr, int lo, int hi);
    void quickSort(int *arr, int lo, int hi);
    
#endif