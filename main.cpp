#include <stdlib.h>
#include <iostream>
#include <thread>

#include "./inc/helpers/menu.hh"

int main() {
    char choise;

    Menu Menu;

    try {
        
        while(choise != '0') {
            Menu.menuDef();
            std::cin >> choise;

            switch(choise) {
                case '1':

                    std::cout << "* Hello World!!! *\n" << std::endl;

                break;

            }
        }

    } catch(const std::runtime_error& e) {
        std::cerr << "Something go wrong" << e.what() << '\n';
        exit(1);
    }
}