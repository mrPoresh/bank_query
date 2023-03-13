#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./tiket.hh"

template <typename Data>
class DNode {           /* | <-- | * | data | * | --> */
public:
    DNode();

    bool isEmptyData() const;

    void setTask(Data* task);

    //# add Tiket() *tiket = adr to new tiket

private:
    Data* data = NULL;      
    DNode* prev;
    DNode* next;

    friend class DLinkedList;
};

template <typename Data>
DNode<Data>::DNode() {
    std::cout << "Node Constructor\n" << std::endl;
}

template <typename Data>
bool DNode<Data>::isEmptyData() const {
    std::cout << "Check Node Data\n" << std::endl;
    return (data == NULL);
}

template <typename Data>
void DNode<Data>::setTask(Data* task) {
/*     if (isEmptyData()) { */
        if (next != NULL) {
            if (next->isEmptyData()) {
                std::cout << "Send Data in next Node\n" << std::endl;
                next->setTask(task);

            } else {
                std::cout << "Set Data in Node\n" << std::endl;
                data = task;
            }

        } else {
            std::cout << "Set Data in Head\n" << std::endl;
            data = task;
        }
/*     } else {
        std::cout << "Query is Full\n" << std::endl;
    } */
}