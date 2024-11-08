#pragma once
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "node.h"
#include <iostream>

using namespace std;

/**
 * @class DoublyLinkedList
 * @brief Klasa implementuj�ca list� dwukierunkow�.
 *
 * Ta klasa umo�liwia operacje na li�cie dwukierunkowej, takie jak dodawanie,
 * usuwanie i wy�wietlanie element�w w obu kierunkach.
 *
 * @tparam T Typ element�w przechowywanych w li�cie.
 */
template <class T>
class DoublyLinkedList {
private:
    Node<T>* head = nullptr; ///< Wska�nik na pierwszy element listy
    Node<T>* tail = nullptr; ///< Wska�nik na ostatni element listy
    int counter = 0;         ///< Licznik element�w na li�cie
public:
    /** Konstruktor domy�lny */
    DoublyLinkedList() = default;

    /**
     * @brief Wy�wietla wszystkie elementy listy od pocz�tku do ko�ca.
     *
     * Funkcja przechodzi przez list� i wy�wietla jej elementy w kolejno�ci od head do tail.
     */
    void show() const;

    /**
     * @brief Dodaje element na pocz�tek listy.
     *
     * Tworzy nowy w�ze� i ustawia go jako pierwszy element listy.
     *
     * @param value Warto�� elementu, kt�ry ma zosta� dodany na pocz�tek.
     */
    void insert_head(const T& value);

    /**
     * @brief Dodaje element na koniec listy.
     *
     * Tworzy nowy w�ze� i ustawia go jako ostatni element listy.
     *
     * @param value Warto�� elementu, kt�ry ma zosta� dodany na koniec.
     */
    void insert_tail(const T& value);

    /**
     * @brief Dodaje element na wybranej pozycji w li�cie.
     *
     * Funkcja pozwala na dodanie elementu na okre�lonej pozycji w li�cie.
     * Je�li pozycja jest poza zakresem, operacja jest ignorowana.
     *
     * @param value Warto�� elementu, kt�ry ma zosta� dodany.
     * @param index Indeks, na kt�rym ma zosta� dodany element.
     */
    void set_index(const T& value, int index);

    /**
     * @brief Usuwa element z pocz�tku listy.
     *
     * Funkcja usuwa pierwszy element listy. Je�li lista jest pusta, nic si� nie dzieje.
     */
    void remove_head();

    /**
     * @brief Usuwa element z ko�ca listy.
     *
     * Funkcja usuwa ostatni element listy. Je�li lista jest pusta, nic si� nie dzieje.
     */
    void remove_tail();

    /**
     * @brief Wy�wietla wszystkie elementy listy w odwrotnej kolejno�ci.
     *
     * Funkcja przechodzi przez list� od tail do head i wy�wietla jej elementy.
     */
    void show_backward() const;

    /**
     * @brief Przechodzi do nast�pnego elementu listy.
     *
     * Funkcja przechodzi przez list� w kierunku od head do tail i wy�wietla warto��
     * nast�pnego elementu po okre�lonym indeksie.
     *
     * @param index Indeks elementu, od kt�rego rozpoczynamy przechodzenie.
     */
    void goNext(int index);

    /**
     * @brief Przechodzi do poprzedniego elementu listy.
     *
     * Funkcja przechodzi przez list� w kierunku od tail do head i wy�wietla warto��
     * poprzedniego elementu przed okre�lonym indeksem.
     *
     * @param index Indeks elementu, od kt�rego rozpoczynamy przechodzenie.
     */
    void goPrevious(int index);
};

// Implementacja metod

/**
 * @brief Wy�wietla wszystkie elementy listy od pocz�tku do ko�ca.
 */
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

/**
 * @brief Dodaje element na pocz�tek listy.
 *
 * Tworzy nowy w�ze� i ustawia go jako pierwszy element listy.
 */
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

/**
 * @brief Dodaje element na koniec listy.
 *
 * Tworzy nowy w�ze� i ustawia go jako ostatni element listy.
 */
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

/**
 * @brief Dodaje element na wybranej pozycji w li�cie.
 *
 * Funkcja pozwala na dodanie elementu na okre�lonej pozycji w li�cie.
 * Je�li pozycja jest poza zakresem, operacja jest ignorowana.
 */
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

/**
 * @brief Usuwa element z pocz�tku listy.
 *
 * Funkcja usuwa pierwszy element listy.
 */
template <class T>
void DoublyLinkedList<T>::remove_head() {
    if (head == nullptr) { // Je�li lista jest pusta, nic nie robimy
        cout << "List is empty!" << endl;
        return;
    }

    Node<T>* node_to_remove = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr; // Ustawiamy poprzedni wska�nik na nullptr
    }
    else {
        tail = nullptr; // Je�li lista jest teraz pusta, ustawiamy tail na nullptr
    }

    delete node_to_remove;
    counter--;
}

/**
 * @brief Usuwa element z ko�ca listy.
 *
 * Funkcja usuwa ostatni element listy.
 */
template <class T>
void DoublyLinkedList<T>::remove_tail() {
    if (tail == nullptr) { // Je�li lista jest pusta, nic nie robimy
        cout << "List is empty!" << endl;
        return;
    }

    Node<T>* node_to_remove = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr; // Ustawiamy nast�pny wska�nik na nullptr
    }
    else {
        head = nullptr; // Je�li lista jest teraz pusta, ustawiamy head na nullptr
    }

    delete node_to_remove;
    counter--;
}

/**
 * @brief Wy�wietla wszystkie elementy listy w odwrotnej kolejno�ci.
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
 * @brief Przechodzi do nast�pnego elementu listy.
 *
 * Funkcja przechodzi do elementu znajduj�cego si� po wskazanym indeksie.
 */
template <class T>
void DoublyLinkedList<T>::goNext(int index) {
    Node<T>* current = head;
    int count = 0;

    // Przechodzimy przez list� a� do wskazanego indeksu
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
 * Funkcja przechodzi do elementu znajduj�cego si� przed wskazanym indeksem.
 */
template <class T>
void DoublyLinkedList<T>::goPrevious(int index) {
    Node<T>* current = head;
    int count = 0;

    // Przechodzimy przez list� a� do wskazanego indeksu
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
