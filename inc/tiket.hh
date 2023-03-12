#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

class Tiket {
public: 
    Tiket(const int execution, const int id);
    ~Tiket();

    int getExecTime();
    int getId();

private:
    int execution;
    int id;
};

Tiket::Tiket(int exec, int num): execution(exec), id(num) {
    std::cout << "Tiket Constr \n" << std::endl;
    std::cout << "id of created Tiket: " << num << " Execution Time: "<< exec << "\n" << std::endl;
};

Tiket::~Tiket() {
    std::cout << "id of deleted Tiket: " << id << "\n" << std::endl;
    //delete &execution;
    //delete &id;
};

int Tiket::getExecTime() {
    return execution;
};

int Tiket::getId() {
    return id;
};