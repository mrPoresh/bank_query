#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./d_node.hh"

class DLinkedList {
public: 
    DLinkedList();
    ~DLinkedList();

    bool isEmpty() const;

    //const Elem& front() const;
    //const Elem& back() const;

    //void addFront(const Elem& e);
    //void addBack(const Elem& e);
    //void removeFront();
    //void removeBack();

protected:
    //void addNode(DNode* v, const Elem& e);
    //void remove(DNode* v);

private:
    DNode* header;
    DNode* trailer;
};

DLinkedList::DLinkedList() {
    std::cout << "List Constr \n" << std::endl;
    header = NULL;
    trailer = NULL;

    //header->next = trailer;
    //trailer->prev = header;

/*     std::cout << "List Constr \n" << std::endl;
    header = new DNode(0, 1);
    trailer = new DNode(1, 2);

    header->next = trailer;
    trailer->prev = header; */
};

bool DLinkedList::isEmpty() const {
    return (header->next == trailer);
};

DLinkedList::~DLinkedList() {
    delete header;
    delete trailer;
};