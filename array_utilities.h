/*  Dan Wilder
 *
 *  University of Missouri - St. Louis
 *  CS 3130 - Design & Analysis of Algorithms
 *  Galina Piatnitskiaia (instructor)
 *  Project #2
 *
 *  array_utilities.h
 *       Header file containing function declarations for functions on arrays.
 */

#include <stdio.h>

#ifndef ARRAY_UTILITIES_H
#define ARRAY_UTILITIES_H

void fprintArray(FILE *stream, int arr[], int size);
void randomInitialize(int arr[], int size, int min, int max);
void copyArray(int dest[], int src[], int size, int start);
void readArrayFile(FILE *stream, int dest[], int size);

#endif