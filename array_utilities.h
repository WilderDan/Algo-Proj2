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

#ifndef ARRAY_UTILITIES_H
#define ARRAY_UTILITIES_H

#include <stdio.h>

void fprintArray(FILE *, int [], int);
void randomInitialize(int [], int, int, int);
void copyArray(int [], int [], int);
void readArrayFile(FILE *, int [], int);

#endif