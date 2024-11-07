#include "pch.h"
#include <iostream>
#include "Doubly_linked_list.h"

using namespace std;


int main()
{
	DoublyLinkedList<int> lista;
	//dodaj na początek
	lista.insert_head(1);
	lista.insert_head(1);
	//dodaj na koniec
	lista.insert_tail(9);
	lista.insert_tail(9);

	lista.set_index(3, 3);
	lista.set_index(3, 3);



	lista.show();

	return 0;
}