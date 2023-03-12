#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./tiket.hh"

class DNode {           /* | <-- | * | data | * | --> */
public:
    DNode();

    //# add Tiket() *tiket = adr to new tiket

private:
    Tiket* tiket;      
    DNode* prev;
    DNode* next;

    friend class DLinkedList;
};

DNode::DNode() {
    std::cout << "Node Constr \n" << std::endl;
}