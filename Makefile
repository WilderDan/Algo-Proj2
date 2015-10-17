CC=gcc
CFLAGS=-g -Wall

HEADERS=array_utilities.h sort_algorithms.h

SOURCES_A=part_a.c array_utilities.c sort_algorithms.c

OBJECTS_A=$(SOURCES_A:.c=.o)

EXECUTABLE_A=run_A


all: $(EXECUTABLE_A)

$(EXECUTABLE_A): $(OBJECTS_A)  
	$(CC) $(OBJECTS_A) -o $(EXECUTABLE_A) -lm

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $*.c -o $*.o
	
.PHONY: clean

clean:
	rm $(OBJECTS_A) $(EXECUTABLE_A)