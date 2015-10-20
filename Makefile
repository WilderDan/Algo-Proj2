#	Dan Wilder
#	
#	University of Missouri - St. Louis
#	CS 3130 - Design & Analysis of Algorithms
#	Galina Piatnitskiaia (instructor)
#	Project #2
#	
#	Makefile

 
CC=gcc
CFLAGS=-g -Wall

HEADERS=array_utilities.h sort_algorithms.h

SOURCES_A=part_a.c array_utilities.c sort_algorithms.c
SOURCES_B=part_b.c array_utilities.c sort_algorithms.c

OBJECTS_A=$(SOURCES_A:.c=.o)
OBJECTS_B=$(SOURCES_B:.c=.o)

EXECUTABLE_A=run_A
EXECUTABLE_B=run_B

all: $(EXECUTABLE_A) $(EXECUTABLE_B)

$(EXECUTABLE_A): $(OBJECTS_A)  
	$(CC) $(OBJECTS_A) -o $(EXECUTABLE_A) -lm
	
$(EXECUTABLE_B): $(OBJECTS_B)  
	$(CC) $(OBJECTS_B) -o $(EXECUTABLE_B) -lm

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $*.c -o $*.o
	
.PHONY: clean

clean:
	rm $(OBJECTS_A) $(OBJECTS_B) $(EXECUTABLE_A) $(EXECUTABLE_B)