#pragma once
#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
    T value;              // Wartoœæ przechowywana w wêŸle
    Node<T>* prev;        // WskaŸnik do poprzedniego wêz³a
    Node<T>* next;        // WskaŸnik do nastêpnego wêz³a

    // Konstruktor ustawiaj¹cy wartoœæ oraz wskaŸniki na nullptr
    explicit Node(T value) : value{ value }, prev{ nullptr }, next{ nullptr } {}
};

#endif // NODE_H
