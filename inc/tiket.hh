#pragma once

#include <stdlib.h>
#include <iostream>

template <typename T>
class Tiket {
public: 
    Tiket(T _value);
    ~Tiket();

    int value;

};

template <typename T>
Tiket<T>::Tiket(T _value) {
    value = _value;
    std::cout << "Value of created Tiket: " << value << "\n" << std::endl;
};

template <typename T>
Tiket<T>::~Tiket() {
    std::cout << "Value of deleted Tiket: " << value << "\n" << std::endl;  
};
