// PE2_Uebungsblatt1_Aufgabe2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include "heap.h"

int main()
{
	heap_t* heap = createHeap();
	printf("heap:\t%p\n", heap);

	insert(heap, 10);

	return 0;
}