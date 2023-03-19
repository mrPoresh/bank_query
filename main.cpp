#include <stdlib.h>
#include <iostream>
#include <thread>


#include "./inc/helpers/menu.hh"
#include "./inc/d_linked_list.hh"
#include "./inc/tiket.hh"

int main() {
    char choise;

    //int size, exec, num;

    Menu Menu;
    TiketType Type;

    Queue* q = new Queue();

    //DLinkedList* Query = NULL;

    try {
        
        while(choise != '0') {
            Menu.menuDef();
            std::cin >> choise;

            switch(choise) {
                case '1':

                    q->addMember(Type = PAYMENT);
        
                break;

                case '2':

                    q->sendMember();
     
                break;

            }
        }

    } catch(const std::runtime_error& e) {
        std::cerr << "Something go wrong -> " << e.what() << '\n';
        exit(1);
    }
};