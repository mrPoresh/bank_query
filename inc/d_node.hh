#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./tiket.hh"

template <typename Data>
class DNode {           /* | <-- | * | data | * | --> */
public:
    DNode();

    //# add Tiket() *tiket = adr to new tiket

private:
    Data* data = NULL;      
    DNode* prev;
    DNode* next;

    friend class DLinkedList;
};

template <typename Data>
DNode<Data>::DNode() {
    std::cout << "Node Constructor \n" << std::endl;
}