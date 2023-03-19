#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

class Tiket {
public: 
    Tiket(int execution, int number);
    ~Tiket();

    int getExecTime() const;
    int getId() const;

private:
    int exec;
    int id;
};

Tiket::Tiket(int execution, int number): exec(execution), id(number) {
    std::cout << "Tiket Constructor \n" << std::endl;
    std::cout << "id of created Tiket: " << id << " Execution Time: "<< exec << "\n" << std::endl;
};

Tiket::~Tiket() {
    std::cout << "id of deleted Tiket: " << id << "\n" << std::endl;
    delete &exec;
    //delete &id;   wtf
};

int Tiket::getExecTime() const {
    return exec;
};

int Tiket::getId() const {
    return id;
};
