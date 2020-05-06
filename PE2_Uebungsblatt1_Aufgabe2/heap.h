#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct heap heap_t;
heap_t* create_heap(void);
void insert(heap_t* h, int val);
int minimum(heap_t* h);
bool extractMin(heap_t* h);
bool getError(heap_t* h);
char* toString(heap_t* h);
void destroyHeap(heap_t* h);

#endif