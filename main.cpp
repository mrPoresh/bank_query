#include <stdlib.h>
#include <iostream>
#include <thread>


#include "./inc/helpers/menu.hh"
#include "./inc/queue.hh"
#include "./inc/tiket.hh"

int main() {
    char choise;

    int size, high;

    Menu Menu;

    Queue* q = new Queue();

    try {
        
        while(choise != '0') {
            Menu.menuDef();
            std::cin >> choise;            

            switch(choise) {
                case '1':
                    std::cout << "Choose an initial Queue size " << "\n" << std::endl;
                    std::cin >> size;

                    for (int i = 0; i < size; i++) {
                        q->addNode();
                    }

                    std::cout << "A - Automode " << "\n" << std::endl;
                    std::cout << "M - Manual   " << "\n" << std::endl;

                    std::cin >> choise;

                    switch(choise) {
                        case 'A':
                            std::cout << "Provide remove operation count " << "\n" << std::endl;
                            std::cin >> high;

                            do {
                                q->addNode();

                                Node<Tiket<int>, int>* node = q->getNode();
                                std::cout << "*** !Node getted! ***" << "\n" << std::endl;

                                node->~Node();

                            } while ((!(q->isEmpty()) || (high == q->a_operations)));
                        break;

                        case 'M':

                        break;
                    }
        
                break;

                case '0':

                    Node<Tiket<int>, int>* node = q->getNode();
                    std::cout << "Geted Node " << "\n" << std::endl;

                    node->~Node();
     
                break;

            }
        }

    } catch(const std::runtime_error& e) {
        std::cerr << "Something go wrong -> " << e.what() << '\n';
        exit(1);
    }
};