#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

#include "./d_node.hh"
#include "./tiket.hh"

enum TiketType { PAYMENT = 4, CONSULTATION = 6, OPEN_ACC = 8, CLOSE_ACC = 10 };

class Queue {
public: 
    Queue();
    ~Queue();

    bool isHead() const;
    bool isTail() const;

    int getHeadId() const;
    int getTailId() const;

    void addMember(int exec);
    void sendMember();

    int id = 1;

protected:
    void createHead(int exec);
    void createTail(int exec);

    void addNode(int exec);

private:
    DNode<Tiket>* head = NULL;
    DNode<Tiket>* tail = NULL;
};

Queue::Queue() {
    std::cout << "Queue Constructor \n" << std::endl;
};

Queue::~Queue() {
    std::cout << "Queue Destructor \n" << std::endl;
    delete head;
    delete tail;
    delete &id;
};

bool Queue::isHead() const {
    return (head != NULL);
};

bool Queue::isTail() const {
    return (tail != NULL);
};

void Queue::createHead(int exec) {
    std::cout << "Create Head \n" << std::endl;
    head = new DNode<Tiket>(exec, id);
    id++;
};

void Queue::createTail(int exec) {
    std::cout << "Create Tail \n" << std::endl;
    tail = new DNode<Tiket>(exec, id);
    head->next = tail; tail->prev = head;
    id++;
};

void Queue::addNode(int exec) {
    std::cout << "Adding new Tiket \n" << std::endl;
    DNode<Tiket>* new_tail = new DNode<Tiket>(exec, id);
    tail->next = new_tail; new_tail->prev = tail;
    tail = new_tail;
    id++;
};

void Queue::addMember(int exec) {
    if (isTail()) {
        addNode(exec);
    } else {
        if (isHead()) {
            createTail(exec);
        } else {    
            createHead(exec);
        }
    }
};

void Queue::sendMember() {
    if (isHead()) {
        if (head->next == tail && isTail()) {
            std::cout << "Id of sended tiket: " << getHeadId() << "\n" << std::endl;
            std::cout << "We are lost tail \n" << std::endl;

            head = tail; head->prev = NULL; tail = NULL;

            std::cout << "Total Bilet Amount: 1\n" << std::endl;

        } else if (head->next == NULL) {
            std::cout << "Id of sended tiket: " << getHeadId() << "\n" << std::endl;
            std::cout << "We are lost last Member \n" << std::endl;

            head = NULL;

            std::cout << "Total Bilet Amount: 0\n" << std::endl;

        } else {
            std::cout << "Id of sended tiket: " << getHeadId() << "\n" << std::endl;
            std::cout << "Sending Member \n" << std::endl;

            head = head->next; head->prev->next = NULL; head->prev = NULL;

            std::cout << "Total Bilet Amount: " << getTailId() - getHeadId() + 1 << "\n" << std::endl;  //
        }
    } else {
        throw std::runtime_error("Head is not defined.");
    }
};

int Queue::getHeadId() const {
    if (isHead()) {
        return head->data->getId();
    } else {
        throw std::runtime_error("Head is not defined.");
    }
}

int Queue::getTailId() const {
    if (isHead()) {
        return tail->data->getId();
    } else {
        throw std::runtime_error("Head is not defined.");
    }
}