#pragma once

#include <stdlib.h>
#include <iostream>
// #include <cmath>

class Tiket {
public: 
    Tiket(const int exec, const int num);
    ~Tiket();

    int getExecTime() const;
    int getId() const;

private:
    int execution;
    int id;
};

Tiket::Tiket(int exec, int num): execution(exec), id(num) {
    std::cout << "Tiket Constructor \n" << std::endl;
    std::cout << "id of created Tiket: " << num << " Execution Time: "<< exec << "\n" << std::endl;
};

Tiket::~Tiket() {
    std::cout << "id of deleted Tiket: " << id << "\n" << std::endl;
    //delete &execution;
    //delete &id;
};

int Tiket::getExecTime() const {
    return execution;
};

int Tiket::getId() const {
    return id;
};
