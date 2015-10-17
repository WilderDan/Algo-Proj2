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
 
 int main() {
     
     // TESTING mergeSort
     
     int A[20];
     
     randomInitialize(A, 20, 1, 9999);
     fprintArray(stdout, A, 20);
     
     mergeSort(A, 0, 19);
     fprintArray(stdout, A, 20);
     
     return 0;
 }