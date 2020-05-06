// PE2_Uebungsblatt1_Aufgabe2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include "heap.h"

int main()
{
	heap_t* heap = create_heap();
	insert(heap, 10);
	insert(heap, 20);
	insert(heap, 30);
	insert(heap, 40);
	printf("%s", toString(heap));
	destroyHeap(heap);

	return EXIT_SUCCESS;
}