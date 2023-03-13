#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./d_node.hh"
#include "./tiket.hh"


class DLinkedList {
public: 
    DLinkedList(int size);
    ~DLinkedList();

    bool isEmptyTrailer() const;

    void extendQuery();
    void addTask(Tiket* task);

protected:
    void addNode(DNode<Tiket>* current_node);

private:
    DNode<Tiket>* header;
    DNode<Tiket>* trailer;
};

DLinkedList::DLinkedList(int size) {
    std::cout << "List Constructor \n" << std::endl;

    header = new DNode<Tiket>();
    trailer = new DNode<Tiket>();

    header->prev = trailer;
    trailer->next = header;

    for(int i = 0; i < size - 2; i++) {
        extendQuery();
    };
};

bool DLinkedList::isEmptyTrailer() const {
    return (trailer->isEmptyData());
};

void DLinkedList::addNode(DNode<Tiket>* current_node) {
    DNode<Tiket>* new_node = new DNode<Tiket>; 
    current_node->next->prev = new_node;       
    new_node->next = current_node->next;
    current_node->next = new_node;
    new_node->prev = current_node;
};

void DLinkedList::extendQuery() {
    addNode(trailer);
};

void DLinkedList::addTask(Tiket* task) {
    trailer->setTask(task);
};

DLinkedList::~DLinkedList() {
    delete header;
    delete trailer;
};