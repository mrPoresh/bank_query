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

                    std::cout << "Size of q: " << q->q_size << "\n" << std::endl;

                    std::cout << "A - Automode " << "\n" << std::endl;
                    std::cout << "S - Stream   " << "\n" << std::endl;

                    std::cin >> choise;

                    switch(choise) {
                        case 'A':
                            std::cout << "Provide max remove operation count " << "\n" << std::endl;
                            std::cin >> high;

                            do {
                                if ((std::rand() % 3 + 0) >= 2) {
                                    q->addNode();
                                }

                                Node<Tiket<int>, int>* node = q->getNode();
                                std::cout << "*** !Node getted! ***" << "\n" << std::endl;

                            } while (!(q->isEmpty()) && !(high == q->r_operations));

                            std::cout << "Size of q: " << q->q_size << "\n" << std::endl;
                        break;

                        case 'S':
                            std::cout << "Provide max remove operation count " << "\n" << std::endl;
                            std::cin >> high;

                            do {
                                q->addNode();

                                Node<Tiket<int>, int>* node = q->getNode();
                                std::cout << "*** !Node getted! ***" << "\n" << std::endl;

                            } while (!(q->isEmpty()) && !(high == q->r_operations));

                            std::cout << "Size of q: " << q->q_size << "\n" << std::endl;
                        break;
                    }
        
                break;

            }
        }

    } catch(const std::runtime_error& e) {
        std::cerr << "Something go wrong -> " << e.what() << '\n';
        exit(1);
    }
};