#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./d_node.hh"
#include "./tiket.hh"

class DLinkedList {
public: 
    DLinkedList();
    ~DLinkedList();

    bool isEmpty() const;

    //const Tiket& front() const;
    //const Tiket& back() const;

    //void addFront(const Tiket& tiket);
    void addBack(Tiket* tiket);
    //void removeFront();
    //void removeBack();

protected:
    void addNode(DNode<Tiket>* next, Tiket* tiket);
    //void remove(DNode* v);

private:
    DNode<Tiket>* header;
    DNode<Tiket>* trailer;
};

DLinkedList::DLinkedList() {
    std::cout << "List Constructor \n" << std::endl;

    header = new DNode<Tiket>();
    trailer = new DNode<Tiket>();

    header->prev = trailer;
    trailer->next = header;
};

bool DLinkedList::isEmpty() const {
    return (header->next == trailer);
};

void DLinkedList::addBack(Tiket* tiket) {
    addNode(trailer, tiket);
};

void DLinkedList::addNode(DNode<Tiket>* current_node, Tiket* tiket) {
    DNode<Tiket>* new_node = new DNode<Tiket>; // new node for new tiket
    new_node->data = tiket;                    // new tiket
    current_node->next->prev = new_node;       // link new node between next and current
    new_node->next = current_node->next;
    current_node->next = new_node;
    new_node->prev = current_node;

    
};

DLinkedList::~DLinkedList() {
    delete header;
    delete trailer;
};