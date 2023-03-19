#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./tiket.hh"
#include "./d_linked_list.hh"

template <typename Data>
class DNode {           /* | <-- | * | data | * | --> */
public:
    DNode(int exec, int id);
    ~DNode();

private:
    Data* data;      
    DNode* prev = NULL;
    DNode* next = NULL;

    friend class Queue;
};

template <typename Data>
DNode<Data>::DNode(int exec, int id) {
    std::cout << "Node Constructor\n" << std::endl;
    data = new Data(exec, id);
};

template <typename Data>
DNode<Data>::~DNode() {
    std::cout << "Node Destructor\n" << std::endl;
    delete data;
    delete prev;
    delete next;
};