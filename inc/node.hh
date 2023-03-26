#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./tiket.hh"
#include "./queue.hh"

template <typename T, typename E>
class Node {
public:
    Node(E value) : data(value) {
        //std::cout << "Node Constructor\n" << std::endl;
    };
    ~Node();

private:
    T data;      
    Node* prev = NULL;
    Node* next = NULL;

    friend class Queue;
};

template <typename T, typename E>
Node<T, E>::~Node() {
    
};