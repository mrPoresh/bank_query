#include <stdlib.h>
#include <iostream>
#include <thread>


#include "./inc/helpers/menu.hh"
#include "./inc/d_linked_list.hh"
#include "./inc/tiket.hh"

int main() {
    char choise;

    int exec, num;

    Menu Menu;
    DLinkedList* Query = new DLinkedList();

    try {
        
        while(choise != '0') {
            Menu.menuDef();
            std::cin >> choise;

            switch(choise) {
                case '1':

                    std::cin >> exec >> num;

                    Tiket* Target = new Tiket(exec, num);
                    Query->addBack(Target);

                    std::cout << "Is empty: " << Query->isEmpty() << "\n" << std::endl;              

                break;

            }
        }

    } catch(const std::runtime_error& e) {
        std::cerr << "Something go wrong" << e.what() << '\n';
        exit(1);
    }
}