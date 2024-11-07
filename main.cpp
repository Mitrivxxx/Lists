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

	lista.remove_tail();
	lista.remove_head();



	lista.show();

	return 0;
}