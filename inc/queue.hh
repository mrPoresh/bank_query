#pragma once

#include <stdlib.h>
#include <iostream>

#include "./node.hh"
#include "./tiket.hh"

class Queue {
public: 
    Queue();
    ~Queue();

    int id = 1;

    int a_operations = 0;
    int r_operations = 0;
    int q_size = 0;

    void addNode();
    Node<Tiket<int>, int>* getNode();
    bool isEmpty() const;

private:
    Node<Tiket<int>, int>* head = NULL;
    Node<Tiket<int>, int>* tail = NULL;
};

Queue::Queue() {
    std::cout << "Queue Constructor \n" << std::endl;
};

Queue::~Queue() {
    std::cout << "Queue Destructor \n" << std::endl;
    /* delete head; ? */  
};

bool Queue::isEmpty() const {
    return (head == NULL);
}

void Queue::addNode() {
    Node<Tiket<int>, int>* node = new Node<Tiket<int>, int>(id);

    if (isEmpty()) {
        head = node; tail = node;
    } else {
        tail->next = node; node->prev = tail; tail = node;
    };

    id++; a_operations++; q_size = q_size + sizeof(node);
    std::cout << "Add operations " << a_operations << "\n" << std::endl;
};

Node<Tiket<int>, int>* Queue::getNode() {
    if(!isEmpty()) {

        Node<Tiket<int>, int>* node = head; r_operations++; q_size = q_size - sizeof(node);

        if (head == tail) {
            head = NULL; tail = NULL;
        } else {
            head->next->prev = NULL; head = head->next;
        }

        std::cout << "Remove operations " << r_operations << "\n" << std::endl;

        return node;

    } else {
        throw std::runtime_error("Head is not defined.");
    }
}