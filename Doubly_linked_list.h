#pragma once
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "node.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList {
private:
    Node<T>* head = nullptr; // WskaŸnik na pierwszy element listy
    Node<T>* tail = nullptr; // WskaŸnik na ostatni element listy
    int counter = 0;         // Licznik elementów na liœcie
public:
    // Konstruktor domyœlny
    DoublyLinkedList() = default;


    void show() const;  //Wyswietl
    void insert_head(const T& value);   //dodaj na poczatek
    void insert_tail(const T& value);    //Dodaj na koncu
    void set_index(const T& value, int index);    //Dodaj na wybranej pozycji
    void remove_head(); //usun poczatek
    void remove_tail(); //usun koniec
};

// wyswietl
template <class T>
void DoublyLinkedList<T>::show() const {
    Node<T>* current = head; // Zaczynamy od pierwszego elementu
    cout << "Lista: ";
    while (current != nullptr) { // Przechodzimy przez ca³¹ listê
        cout << current->value << " "; // Wyœwietlamy wartoœæ bie¿¹cego elementu
        current = current->next; // Przechodzimy do nastêpnego elementu
    }
    cout << endl;
}
// dodaj na poczatek
template <class T>
void DoublyLinkedList<T>::insert_head(const T& value) {
    Node<T>* new_node = new Node<T>{ value }; // Tworzymy nowy wêze³

    if (head == nullptr) { // Jeœli lista jest pusta
        head = tail = new_node; // Nowy wêze³ jest zarówno head, jak i tail
    }
    else {
        new_node->next = head; // Ustawiamy nowy wêze³ jako head
        head->prev = new_node;
        head = new_node;
    }
    counter++; // Zwiêkszamy licznik elementów
}

// dodaj na koniec
template <class T>
void DoublyLinkedList<T>::insert_tail(const T& value) {
    Node<T>* new_node = new Node<T>{ value }; // Tworzymy nowy wêze³

    if (tail == nullptr) { // Jeœli lista jest pusta
        head = tail = new_node; // Nowy wêze³ jest zarówno head, jak i tail
    }
    else {
        tail->next = new_node; // Ustawiamy nowy wêze³ jako tail
        new_node->prev = tail;
        tail = new_node;
    }

    counter++; // Zwiêkszamy licznik elementów
}

//dodaj na wybranej pozycji
template <class T>
void DoublyLinkedList<T>::set_index(const T& value, int index) {
    Node<T>* new_node = new Node<T>{ value }; // Tworzymy nowy wêze³

    if (index < 0 || index > counter) {
        cout << "Index out of bounds!" << endl;
        return; // Indeks poza zakresem
    }

    if (index == 0) {
        insert_head(value); // Dodajemy na pocz¹tku listy
    }
    else if (index == counter) {
        insert_tail(value); // Dodajemy na koñcu listy
    }
    else {
        Node<T>* new_node = new Node<T>{ value };
        Node<T>* current = head;

        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        // Zmieniamy wskaŸniki, aby wstawiæ nowy wêze³ w odpowiedni¹ pozycjê
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;

        counter++;
    }
}
// Implementacja metody remove_head
template <class T>
void DoublyLinkedList<T>::remove_head() {
    if (head == nullptr) { // Jeœli lista jest pusta, nic nie robimy
        cout << "List is empty!" << endl;
        return;
    }

    Node<T>* node_to_remove = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr; // Ustawiamy poprzedni wskaŸnik na nullptr
    }
    else {
        tail = nullptr; // Jeœli lista jest teraz pusta, ustawiamy tail na nullptr
    }

    delete node_to_remove;
    counter--;
}

// Implementacja metody remove_tail
template <class T>
void DoublyLinkedList<T>::remove_tail() {
    if (tail == nullptr) { // Jeœli lista jest pusta, nic nie robimy
        cout << "List is empty!" << endl;
        return;
    }

    Node<T>* node_to_remove = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr; // Ustawiamy nastêpny wskaŸnik na nullptr
    }
    else {
        head = nullptr; // Jeœli lista jest teraz pusta, ustawiamy head na nullptr
    }

    delete node_to_remove;
    counter--;
}

#endif // DOUBLY_LINKED_LIST_H

