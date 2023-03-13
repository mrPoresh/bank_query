#pragma once

#include <stdlib.h>
#include <iostream>

class Menu {
    public:
    
        Menu();
        ~Menu();

        void menuDef() {
            std::cout << "\n*****      Main Menu           *****\n" << std::endl;
            std::cout << "\n***** 1 - Create Tiket         *****\n" << std::endl;
            std::cout << "\n***** 2 - Get back  Elem       *****\n" << std::endl;
            std::cout << "\n***** 3 - Add to front of List *****\n" << std::endl;
            std::cout << "\n***** 4 - Add to back  of List *****\n" << std::endl;
            std::cout << "\n***** 5 - Remove from front    *****\n" << std::endl;
            std::cout << "\n***** 6 - Remove from back     *****\n" << std::endl;
        };

};

Menu::Menu() {
    std::cout << "\n******  Start  Program  ******\n" << std::endl;
}

Menu::~Menu() {
    std::cout << "\n******  Finish Program  ******\n" << std::endl;
}