#include <stdlib.h>
#include <iostream>
#include <thread>


#include "./inc/helpers/menu.hh"
#include "./inc/d_linked_list.hh"

int main() {
    char choise;

    Menu Menu;
    DLinkedList* query = new DLinkedList();

    try {
        
        while(choise != '0') {
            Menu.menuDef();
            std::cin >> choise;

            switch(choise) {
                case '1':

                    bool isEmpty = query->isEmpty();
                    std::cout << "\nisEmpty -> " << isEmpty << std::endl;

                    

                break;

            }
        }

    } catch(const std::runtime_error& e) {
        std::cerr << "Something go wrong" << e.what() << '\n';
        exit(1);
    }
}