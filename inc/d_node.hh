#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

typedef int Elem;       /* in plans, change it to class Tiket, which will keep data */
class DNode {           /* | <-- | * | data | * | --> */
private:
    Elem elem;      
    DNode* prev;
    DNode* next;

    friend class DLinkedList;
};