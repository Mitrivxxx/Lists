#pragma once
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "node.h"
#include <iostream>

using namespace std;

/**
 * @class DoublyLinkedList
 * @brief Klasa implementuj¹ca listê dwukierunkow¹.
 *
 * Ta klasa umo¿liwia operacje na liœcie dwukierunkowej, takie jak dodawanie,
 * usuwanie i wyœwietlanie elementów w obu kierunkach.
 *
 * @tparam T Typ elementów przechowywanych w liœcie.
 */
template <class T>
class DoublyLinkedList {
private:
    Node<T>* head = nullptr; ///< WskaŸnik na pierwszy element listy
    Node<T>* tail = nullptr; ///< WskaŸnik na ostatni element listy
    int counter = 0;         ///< Licznik elementów na liœcie
public:
    /** Konstruktor domyœlny */
    DoublyLinkedList() = default;

    /**
     * @brief Wyœwietla wszystkie elementy listy od pocz¹tku do koñca.
     *
     * Funkcja przechodzi przez listê i wyœwietla jej elementy w kolejnoœci od head do tail.
     */
    void show() const;

    /**
     * @brief Dodaje element na pocz¹tek listy.
     *
     * Tworzy nowy wêze³ i ustawia go jako pierwszy element listy.
     *
     * @param value Wartoœæ elementu, który ma zostaæ dodany na pocz¹tek.
     */
    void insert_head(const T& value);

    /**
     * @brief Dodaje element na koniec listy.
     *
     * Tworzy nowy wêze³ i ustawia go jako ostatni element listy.
     *
     * @param value Wartoœæ elementu, który ma zostaæ dodany na koniec.
     */
    void insert_tail(const T& value);

    /**
     * @brief Dodaje element na wybranej pozycji w liœcie.
     *
     * Funkcja pozwala na dodanie elementu na okreœlonej pozycji w liœcie.
     * Jeœli pozycja jest poza zakresem, operacja jest ignorowana.
     *
     * @param value Wartoœæ elementu, który ma zostaæ dodany.
     * @param index Indeks, na którym ma zostaæ dodany element.
     */
    void set_index(const T& value, int index);

    /**
     * @brief Usuwa element z pocz¹tku listy.
     *
     * Funkcja usuwa pierwszy element listy. Jeœli lista jest pusta, nic siê nie dzieje.
     */
    void remove_head();

    /**
     * @brief Usuwa element z koñca listy.
     *
     * Funkcja usuwa ostatni element listy. Jeœli lista jest pusta, nic siê nie dzieje.
     */
    void remove_tail();

    /**
     * @brief Wyœwietla wszystkie elementy listy w odwrotnej kolejnoœci.
     *
     * Funkcja przechodzi przez listê od tail do head i wyœwietla jej elementy.
     */
    void show_backward() const;

    /**
     * @brief Przechodzi do nastêpnego elementu listy.
     *
     * Funkcja przechodzi przez listê w kierunku od head do tail i wyœwietla wartoœæ
     * nastêpnego elementu po okreœlonym indeksie.
     *
     * @param index Indeks elementu, od którego rozpoczynamy przechodzenie.
     */
    void goNext(int index);

    /**
     * @brief Przechodzi do poprzedniego elementu listy.
     *
     * Funkcja przechodzi przez listê w kierunku od tail do head i wyœwietla wartoœæ
     * poprzedniego elementu przed okreœlonym indeksem.
     *
     * @param index Indeks elementu, od którego rozpoczynamy przechodzenie.
     */
    void goPrevious(int index);
};

// Implementacja metod

/**
 * @brief Wyœwietla wszystkie elementy listy od pocz¹tku do koñca.
 */
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

/**
 * @brief Dodaje element na pocz¹tek listy.
 *
 * Tworzy nowy wêze³ i ustawia go jako pierwszy element listy.
 */
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

/**
 * @brief Dodaje element na koniec listy.
 *
 * Tworzy nowy wêze³ i ustawia go jako ostatni element listy.
 */
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

/**
 * @brief Dodaje element na wybranej pozycji w liœcie.
 *
 * Funkcja pozwala na dodanie elementu na okreœlonej pozycji w liœcie.
 * Jeœli pozycja jest poza zakresem, operacja jest ignorowana.
 */
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

/**
 * @brief Usuwa element z pocz¹tku listy.
 *
 * Funkcja usuwa pierwszy element listy.
 */
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

/**
 * @brief Usuwa element z koñca listy.
 *
 * Funkcja usuwa ostatni element listy.
 */
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

/**
 * @brief Wyœwietla wszystkie elementy listy w odwrotnej kolejnoœci.
 */
template <class T>
void DoublyLinkedList<T>::show_backward() const {
    Node<T>* current = tail;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->prev;
    }
    cout << endl;
}

/**
 * @brief Przechodzi do nastêpnego elementu listy.
 *
 * Funkcja przechodzi do elementu znajduj¹cego siê po wskazanym indeksie.
 */
template <class T>
void DoublyLinkedList<T>::goNext(int index) {
    Node<T>* current = head;
    int count = 0;

    // Przechodzimy przez listê a¿ do wskazanego indeksu
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "No next element found." << endl;
        return;
    }

    cout << "Next element: " << current->next->value << endl;
}

/**
 * @brief Przechodzi do poprzedniego elementu listy.
 *
 * Funkcja przechodzi do elementu znajduj¹cego siê przed wskazanym indeksem.
 */
template <class T>
void DoublyLinkedList<T>::goPrevious(int index) {
    Node<T>* current = head;
    int count = 0;

    // Przechodzimy przez listê a¿ do wskazanego indeksu
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    if (current == nullptr || current->prev == nullptr) {
        cout << "No previous element found." << endl;
        return;
    }

    cout << "Previous element: " << current->prev->value << endl;
}

#endif // DOUBLY_LINKED_LIST_H
