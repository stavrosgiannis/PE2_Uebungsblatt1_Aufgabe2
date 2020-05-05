#include "heap.h"

typedef struct heap {
	int size;
	int next;
	int* values;
	bool error;
}heap_t;

/**
* erzeugt ein leeres Heap "Objekt"
* @return *heap
*/
heap_t* createHeap() {
	heap_t* h = (heap_t*)calloc(1, sizeof(heap_t));
	h->size = 1;
	h->next = 0;
	h->values = (int*)calloc(1, sizeof(int));
	h->error = false;
	return h;
}

void increase_capacity(heap_t* h) {
	int i = 0;
	while (pow(2, i) <= h->size) {
		i++;
	}
	printf("in increase_capacity(): i nach der while-Schleife: %i\n", i);
	h->size = (int)pow(2, i) * 2 - 1;
	printf("in increase_capacity(): h->size nach Erhoehung der Kapazitaet: %i\n", h->size);
	h->values = realloc(h, sizeof(int) * h->size);
}

/**
 * Fügt den Wert val in den Heap h ein
 * @param h
 * @param val
 * @return
 */
void insert(heap_t* h, int val) {
	if (h->size == h->next) {
		printf("in insert(): Erhoehe Kapazitaet...\n");
		increase_capacity(h);
	}
	else {
		printf("in insert(): Fuege ein ohne Speicherkapazitaet zu erhoehen...\n");
	}
	printf("in insert(): Vor Einfuegen: h->next: %i\n", h->next);
	printf("in insert(): current_position: %i\n", h->next);
	h->values[h->next] = val;
	printf("in insert(): h->values[current_position]: %i, current_position: %i\n", h->values[h->next], h->next);
	h->next = h->next + 1;
	printf("in insert(): h->values[current_position]: %i, h->next: %i, current_position: %i\n", h->values[h->next], h->next, h->next);
}