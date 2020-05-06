/**
* @file   main.c
* @author Stavros Giannis
* @date   04.05.2020
* @see    heap.h for documenation.
*
* Min-Heap Algorithmus
*/

#include "heap.h"
#pragma warning(disable:4996)

struct heap {
	int size;
	int next;
	int* values;
	int error;
};

/**
 * erzeugt einen leeren Heap
 * @return *heap
 */
heap_t* create_heap(void) {
	heap_t* h;
	h = (heap_t*)calloc(1, sizeof(heap_t));
	h->size = 1;
	h->next = 0;
	h->values = (int*)calloc(1, sizeof(int));
	return h;
}

/**
 * Vergrößert den Heap
 * @param h
 */
void increaseMemory(heap_t* h) {
	int i = 0;
	while (pow(2, i) <= h->size) {
		i++;
	}
	h->size = (int)pow(2, i) * 2 - 1;
	h->values = realloc(h, sizeof(int) * h->size);
}

/**
 * Gibt an, ob der Heap leer ist
 * @param h
 * @return true, wenn der Heap leer ist
 * @return false, wenn der Heap mind. 1 Element hat
 */
bool isEmpty(heap_t* h) {
	if (h->next > 0) {
		return false;
	}
	else {
		return true;
	}
}

/**
 * Fügt den Wert val in den Heap h ein
 * @param h
 * @param val
 */
void insert(heap_t* h, int val) {
	if (h->size == h->next) {
		increaseMemory(h);
	}
	int current_position = h->next;
	h->values[current_position] = val;
	h->next = current_position + 1;
}

/**
 * Liefert das minimale Element des Heaps h
 * @param h
 * @return -1 OR h->values[0]
 */
int minimum(heap_t* h) {
	if (h->next == 0) {
		h->error = 1;
		return -1;
	}
	else {
		return h->values[0];
	}
}

/**
 * Entfernt das minimale Element aus dem Heap h
 * @param h
 * @return	return h->error;
 */
bool extractMin(heap_t* h) {
	if (h->size == 0) {
		h->error = 1;
		return h->error;
	}

	for (int i = 0; i < h->size - 1; i++) {
		h->values[i] = h->values[i + 1];      //nächstes element wird nächtkleineres element sein
	}

	h->size -= 1;

	return h->error;
}

/**
 * Liefert den Inhalt der Fehlervariablen des Heaps h
 * @param h
 * @return h->error
 */
bool getError(heap_t* h) {
	return h->error;
}

/**
 * Liefert den Inhalt des Heaps h als String
 * @param h
 * @return heap_string
 */
char* toString(heap_t* h) {
	char* heap_string = (char*)calloc(h->size * 14, sizeof(char));
	if (!isEmpty(h)) {
		sprintf(heap_string, "%d", h->values[0]);
		if (h->next > 1) {
			for (int i = 1; i < h->next; i++) {
				strncat(heap_string, ", ", 3);
				char* new_int = (char*)calloc(12, sizeof(char));
				sprintf(new_int, "%d", h->values[i]);
				strncat(heap_string, new_int, 12);
				free(new_int);
			}
		}
	}
	return heap_string;
}

/**
 * Zerstört den Heap h, gibt belegten Speicherplatz frei
 * @param h
 */
void destroyHeap(heap_t* h) {
	free(h->values);
	free(h);
}