#pragma once
#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
    T value;              // Warto�� przechowywana w w�le
    Node<T>* prev;        // Wska�nik do poprzedniego w�z�a
    Node<T>* next;        // Wska�nik do nast�pnego w�z�a

    // Konstruktor ustawiaj�cy warto�� oraz wska�niki na nullptr
    explicit Node(T value) : value{ value }, prev{ nullptr }, next{ nullptr } {}
};

#endif // NODE_H
