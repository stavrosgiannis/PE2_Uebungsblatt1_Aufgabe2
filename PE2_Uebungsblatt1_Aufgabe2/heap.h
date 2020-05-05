#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct heap heap_t;
heap_t* create_heap();
void insert(heap_t* h, int val);
int minimum(heap_t* h);
bool extract_min(heap_t* h);
bool get_error(heap_t* h);
char* to_string(heap_t* h);
void destroy_heap(heap_t* h);
