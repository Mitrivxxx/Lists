#pragma once
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "node.h"
#include <iostream>

using namespace std;

/**
 * @class DoublyLinkedList
 * @brief Klasa implementujaca liste dwukierunkowa.
 *
 * Ta klasa umozliwia operacje na liscie dwukierunkowej, takie jak dodawanie,
 * usuwanie i wyswietlanie elementow w obu kierunkach.
 *
 * @tparam T Typ elementow przechowywanych w liscie.
 */
template <class T>
class DoublyLinkedList {
private:
    Node<T>* head = nullptr; ///< Wskaznik na pierwszy element listy
    Node<T>* tail = nullptr; ///< Wskaznik na ostatni element listy
    int counter = 0;         ///< Licznik elementow na liscie
public:
    /** Konstruktor domyslny */
    DoublyLinkedList() = default;

    /**
     * @brief Wyswietla wszystkie elementy listy od poczatku do konca.
     *
     * Funkcja przechodzi przez liste i wyswietla jej elementy w kolejnosci od head do tail.
     */
    void show() const;

    /**
     * @brief Dodaje element na poczatek listy.
     *
     * Tworzy nowy wezel i ustawia go jako pierwszy element listy.
     *
     * @param value Wartosc elementu, ktory ma zostac dodany na poczatek.
     */
    void insert_head(const T& value);

    /**
     * @brief Dodaje element na koniec listy.
     *
     * Tworzy nowy wezel i ustawia go jako ostatni element listy.
     *
     * @param value Wartosc elementu, ktory ma zostac dodany na koniec.
     */
    void insert_tail(const T& value);

    /**
     * @brief Dodaje element na wybranej pozycji w liscie.
     *
     * Funkcja pozwala na dodanie elementu na okreslonej pozycji w liscie.
     * Jezeli pozycja jest poza zakresem, operacja jest ignorowana.
     *
     * @param value Wartosc elementu, ktory ma zostac dodany.
     * @param index Indeks, na ktorym ma zostac dodany element.
     */
    void set_index(const T& value, int index);

    /**
     * @brief Usuwa element z poczatku listy.
     *
     * Funkcja usuwa pierwszy element listy. Jezeli lista jest pusta, nic sie nie dzieje.
     */
    void remove_head();

    /**
     * @brief Usuwa element z konca listy.
     *
     * Funkcja usuwa ostatni element listy. Jezeli lista jest pusta, nic sie nie dzieje.
     */
    void remove_tail();

    /**
     * @brief Wyswietla wszystkie elementy listy w odwrotnej kolejnosci.
     *
     * Funkcja przechodzi przez liste od tail do head i wyswietla jej elementy.
     */
    void show_backward() const;

    /**
     * @brief Przechodzi do nastepnego elementu listy.
     *
     * Funkcja przechodzi przez liste w kierunku od head do tail i wyswietla wartosc
     * nastepnego elementu po okreslonym indeksie.
     *
     * @param index Indeks elementu, od ktorego rozpoczynamy przechodzenie.
     */
    void goNext(int index);

    /**
     * @brief Przechodzi do poprzedniego elementu listy.
     *
     * Funkcja przechodzi przez liste w kierunku od tail do head i wyswietla wartosc
     * poprzedniego elementu przed okreslonym indeksem.
     *
     * @param index Indeks elementu, od ktorego rozpoczynamy przechodzenie.
     */
    void goPrevious(int index);
};

// Implementacja metod

/**
 * @brief Wyswietla wszystkie elementy listy od poczatku do konca.
 */
template <class T>
void DoublyLinkedList<T>::show() const {
    Node<T>* current = head; // Zaczynamy od pierwszego elementu
    cout << "Wyswietl cala liste od poczatku: ";
    while (current != nullptr) { // Przechodzimy przez cala liste
        cout << current->value << " "; // Wyswietlamy wartosc biezacego elementu
        current = current->next; // Przechodzimy do nastepnego elementu
    }
    cout << endl;
}

/**
 * @brief Dodaje element na poczatek listy.
 *
 * Tworzy nowy wezel i ustawia go jako pierwszy element listy.
 */
template <class T>
void DoublyLinkedList<T>::insert_head(const T& value) {
    Node<T>* new_node = new Node<T>{ value }; // Tworzymy nowy wezel

    if (head == nullptr) { // Jezeli lista jest pusta
        head = tail = new_node; // Nowy wezel jest zarowno head, jak i tail
    }
    else {
        new_node->next = head; // Ustawiamy nowy wezel jako head
        head->prev = new_node;
        head = new_node;
    }
    counter++; // Zwiekszamy licznik elementow
}

/**
 * @brief Dodaje element na koniec listy.
 *
 * Tworzy nowy wezel i ustawia go jako ostatni element listy.
 */
template <class T>
void DoublyLinkedList<T>::insert_tail(const T& value) {
    Node<T>* new_node = new Node<T>{ value }; // Tworzymy nowy wezel

    if (tail == nullptr) { // Jezeli lista jest pusta
        head = tail = new_node; // Nowy wezel jest zarowno head, jak i tail
    }
    else {
        tail->next = new_node; // Ustawiamy nowy wezel jako tail
        new_node->prev = tail;
        tail = new_node;
    }

    counter++; // Zwiekszamy licznik elementow
}

/**
 * @brief Dodaje element na wybranej pozycji w liscie.
 *
 * Funkcja pozwala na dodanie elementu na okreslonej pozycji w liscie.
 * Jezeli pozycja jest poza zakresem, operacja jest ignorowana.
 */
template <class T>
void DoublyLinkedList<T>::set_index(const T& value, int index) {
    Node<T>* new_node = new Node<T>{ value }; // Tworzymy nowy wezel

    if (index < 0 || index > counter) {
        cout << "Index poza zakresem!" << endl;
        return; // Indeks poza zakresem
    }

    if (index == 0) {
        insert_head(value); // Dodajemy na poczatku listy
    }
    else if (index == counter) {
        insert_tail(value); // Dodajemy na koncu listy
    }
    else {
        Node<T>* current = head;

        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        // Zmieniamy wskazniki, aby wstawic nowy wezel w odpowiednia pozycje
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;

        counter++;
    }
}

/**
 * @brief Usuwa element z poczatku listy.
 *
 * Funkcja usuwa pierwszy element listy.
 */
template <class T>
void DoublyLinkedList<T>::remove_head() {
    if (head == nullptr) { // Jezeli lista jest pusta, nic nie robimy
        cout << "Lista jest pusta!" << endl;
        return;
    }

    Node<T>* node_to_remove = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr; // Ustawiamy poprzedni wskaznik na nullptr
    }
    else {
        tail = nullptr; // Jezeli lista jest teraz pusta, ustawiamy tail na nullptr
    }

    delete node_to_remove;
    counter--;
}

/**
 * @brief Usuwa element z konca listy.
 *
 * Funkcja usuwa ostatni element listy.
 */
template <class T>
void DoublyLinkedList<T>::remove_tail() {
    if (tail == nullptr) { // Jezeli lista jest pusta, nic nie robimy
        cout << "Lista jest pusta!" << endl;
        return;
    }

    Node<T>* node_to_remove = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr; // Ustawiamy nastepny wskaznik na nullptr
    }
    else {
        head = nullptr; // Jezeli lista jest teraz pusta, ustawiamy head na nullptr
    }

    delete node_to_remove;
    counter--;
}

/**
 * @brief Wyswietla wszystkie elementy listy w odwrotnej kolejnosci.
 */
template <class T>
void DoublyLinkedList<T>::show_backward() const {
    Node<T>* current = tail;
    cout << "Wyswietl cala liste od konca: ";
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->prev;
    }
    cout << endl;
}

/**
 * @brief Przechodzi do nastepnego elementu listy.
 *
 * Funkcja przechodzi do elementu znajdujacego sie po wskazanym indeksie.
 */
template <class T>
void DoublyLinkedList<T>::goNext(int index) {
    Node<T>* current = head;
    int count = 0;
    // Przechodzimy przez liste az do wskazanego indeksu
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Brak nastepnego elementu." << endl;
        return;
    }

    cout << "Nastepnym elementem jest: " << current->next->value << " porownujac do indeksu: " << index << endl;
}

/**
 * @brief Przechodzi do poprzedniego elementu listy.
 *
 * Funkcja przechodzi do elementu znajdujacego sie przed wskazanym indeksem.
 */
template <class T>
void DoublyLinkedList<T>::goPrevious(int index) {
    if (index <= 0) {
        std::cout << "Nie ma poprzedniego elementu\n";
        return;
    }

    if (index >= counter) {
        std::cout << "Index poza zakresem\n";
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    cout << "Nastepnym elementem jest: " << current->value << " porownujac do indeksu: " << index << endl;
}

#endif // DOUBLY_LINKED_LIST_H
