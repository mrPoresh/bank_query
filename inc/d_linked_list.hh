#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./d_node.hh"

class DLinkedList {
public: 
    DLinkedList();
    ~DLinkedList();

    bool empty() const;

    const Elem& front() const;
    const Elem& back() const;

    void addFront(const Elem& e);
    void addBack(const Elem& e);
    void removeFront();
    void removeBack();

protected:
    void add(DNode* v, const Elem& e);
    void remove(DNode* v);

private:
    DNode* header;
    DNode* trailer;
};