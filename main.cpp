#include <stdlib.h>
#include <iostream>
#include <thread>


#include "./inc/helpers/menu.hh"
#include "./inc/d_linked_list.hh"
#include "./inc/tiket.hh"

int main() {
    char choise;

    int size, exec, num;

    Menu Menu;
    //DLinkedList* Query = new DLinkedList();

    DLinkedList* Query = NULL;

    try {
        
        while(choise != '0') {
            Menu.menuDef();
            std::cin >> choise;

            switch(choise) {
                case '1':

                    std::cin >> size;

                    if (Query == NULL) {
                        Query = new DLinkedList(size);
                    } else {
                        std::cout << "Query exist\n" << std::endl;
                    }          

                break;

                case '4':

                    if (Query != NULL) {    //// not correct 
                        if (Query->isEmptyTrailer()) {
                            std::cin >> exec >> num;
                            Query->addTask(new Tiket(exec, num));
                        } else {
                            std::cout << "Query too busy\n" << std::endl;
                        }

                    } else {
                        std::cout << "Query dont exist\n" << std::endl;
                    }       

                break;

            }
        }

    } catch(const std::runtime_error& e) {
        std::cerr << "Something go wrong" << e.what() << '\n';
        exit(1);
    }
};