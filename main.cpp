#include "pch.h"
#include <iostream>
#include "Doubly_linked_list.h"

using namespace std;
//jakas zmiana 1

/**
 * @file main.cpp
 * @brief Przykład użycia listy dwukierunkowej.
 *
 * W tym przykładzie demonstrujemy jak dodać, usunąć i wyświetlić elementy w liście dwukierunkowej.
 * Listę implementujemy za pomocą klasy `DoublyLinkedList` i wykonujemy operacje na elementach.
 */

 /**
  * @brief Główna funkcja wykonująca operacje na liście.
  *
  * Funkcja tworzy listę, dodaje elementy na początek i koniec, usuwa elementy,
  * a następnie wyświetla listę w obu kierunkach.
  */
int main() {
    /**
     * Tworzymy instancję listy dwukierunkowej.
     */
    DoublyLinkedList<int> lista;

    /**
     * Dodajemy elementy na początek listy.
     * Każdy nowy element będzie dodawany przed istniejącymi elementami.
     */
    lista.insert_head(4);  ///< Dodaj na początek 4
    lista.insert_head(5);  ///< Dodaj na początek 5
    lista.insert_head(6);  ///< Dodaj na początek 6
    lista.insert_head(1);  ///< Dodaj na początek 1
    lista.insert_head(1);  ///< Dodaj na początek 1 (ponownie)

    /**
     * Dodajemy elementy na koniec listy.
     * Każdy nowy element będzie dodawany po ostatnim istniejącym elemencie.
     */
    lista.insert_tail(9);  ///< Dodaj na koniec 9
    lista.insert_tail(9);  ///< Dodaj na koniec 9 (ponownie)

    /**
     * Usuwamy elementy z końca i początku listy.
     * Usuwanie z początku (remove_head) i z końca (remove_tail).
     */
    lista.remove_tail();  ///< Usuwamy element z końca
    lista.remove_head();  ///< Usuwamy element z początku

    /**
     * Wyświetlamy listę w kolejności od początku do końca.
     */
    lista.show();  ///< Wyświetl listę od początku do końca

    /**
     * Wyświetlamy listę w kolejności odwrotnej, od końca do początku.
     */
    lista.show_backward();  ///< Wyświetl listę od końca do początku

    /**
     * Przechodzimy o dwa elementy do przodu i do tyłu w liście.
     * Funkcje `goNext` i `goPrevious` umożliwiają poruszanie się po liście.
     */
    lista.goNext(2);  ///< Przejdź o 2 elementy do przodu
    lista.goPrevious(2);  ///< Przejdź o 2 elementy do tyłu

    /**
     * Ponownie wyświetlamy listę po przejściu do przodu i do tyłu.
     */
    lista.show();  ///< Wyświetl listę ponownie po operacjach przechodzenia

    return 0;
}