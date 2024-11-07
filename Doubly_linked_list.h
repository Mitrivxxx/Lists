#pragma once
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "node.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList {
private:
    Node<T>* head = nullptr; // Wska�nik na pierwszy element listy
    Node<T>* tail = nullptr; // Wska�nik na ostatni element listy
    int counter = 0;         // Licznik element�w na li�cie
public:
    // Konstruktor domy�lny
    DoublyLinkedList() = default;


    void show() const;  //Wyswietl
    void insert_head(const T& value);   //dodaj na poczatek
    void insert_tail(const T& value);    //Dodaj na koncu
    void set_index(const T& value, int index);    //Dodaj na wybranej pozycji
};

// wyswietl
template <class T>
void DoublyLinkedList<T>::show() const {
    Node<T>* current = head; // Zaczynamy od pierwszego elementu
    cout << "Lista: ";
    while (current != nullptr) { // Przechodzimy przez ca�� list�
        cout << current->value << " "; // Wy�wietlamy warto�� bie��cego elementu
        current = current->next; // Przechodzimy do nast�pnego elementu
    }
    cout << endl;
}
// dodaj na poczatek
template <class T>
void DoublyLinkedList<T>::insert_head(const T& value) {
    Node<T>* new_node = new Node<T>{ value }; // Tworzymy nowy w�ze�

    if (head == nullptr) { // Je�li lista jest pusta
        head = tail = new_node; // Nowy w�ze� jest zar�wno head, jak i tail
    }
    else {
        new_node->next = head; // Ustawiamy nowy w�ze� jako head
        head->prev = new_node;
        head = new_node;
    }
    counter++; // Zwi�kszamy licznik element�w
}

// dodaj na koniec
template <class T>
void DoublyLinkedList<T>::insert_tail(const T& value) {
    Node<T>* new_node = new Node<T>{ value }; // Tworzymy nowy w�ze�

    if (tail == nullptr) { // Je�li lista jest pusta
        head = tail = new_node; // Nowy w�ze� jest zar�wno head, jak i tail
    }
    else {
        tail->next = new_node; // Ustawiamy nowy w�ze� jako tail
        new_node->prev = tail;
        tail = new_node;
    }

    counter++; // Zwi�kszamy licznik element�w
}


template <class T>
void DoublyLinkedList<T>::set_index(const T& value, int index) {
    Node<T>* new_node = new Node<T>{ value }; // Tworzymy nowy w�ze�

    if (index < 0 || index > counter) {
        cout << "Index out of bounds!" << endl;
        return; // Indeks poza zakresem
    }

    if (index == 0) {
        insert_head(value); // Dodajemy na pocz�tku listy
    }
    else if (index == counter) {
        insert_tail(value); // Dodajemy na ko�cu listy
    }
    else {
        Node<T>* new_node = new Node<T>{ value };
        Node<T>* current = head;

        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        // Zmieniamy wska�niki, aby wstawi� nowy w�ze� w odpowiedni� pozycj�
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;

        counter++;
    }
}









#endif // DOUBLY_LINKED_LIST_H

