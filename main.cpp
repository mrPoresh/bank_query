#include <stdlib.h>
#include <iostream>
#include <thread>
#include <cstdlib>


#include "./inc/helpers/menu.hh"
#include "./inc/queue.hh"
#include "./inc/tiket.hh"

size_t memoryUsage = 0;

struct MemData
{
	size_t size;
};

void* operator new(size_t size)
{
    memoryUsage += size;
    void* ptr = std::malloc(size + sizeof(MemData));
    *reinterpret_cast<MemData*>(ptr) = MemData{ size };
    ptr = reinterpret_cast<char*>(ptr) + sizeof(MemData);
    if (!ptr) throw std::bad_alloc();
    return ptr;
}

void operator delete(void* ptr) noexcept
{
    ptr = reinterpret_cast<char*>(ptr) - sizeof(MemData);
	size_t size = reinterpret_cast<MemData*>(ptr)->size;
	memoryUsage -= size;
    std::free(ptr);
}

int main() {
    char choise;

    int size, high;

    Menu Menu;

    try {
        
        while(choise != '0') {
            std::cout << "Memory Used in while " << memoryUsage << "\n" << std::endl;

            Queue* q = new Queue();

            Menu.menuDef();
            std::cin >> choise;            

            switch(choise) {
                case '1':
                    std::cout << "Choose an initial Queue size " << "\n" << std::endl;
                    std::cin >> size;

                    for (int i = 0; i < size; i++) {
                        q->addNode();
                    }

                    std::cout << "Memory Used After Q init " << memoryUsage << "\n" << std::endl;

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

                                delete node;

                            } while (!(q->isEmpty()) && !(high == q->r_operations));

                            std::cout << "Memory Used After get " << memoryUsage << "\n" << std::endl;
                        break;

                        case 'S':
                            std::cout << "Provide max remove operation count " << "\n" << std::endl;
                            std::cin >> high;

                            do {
                                q->addNode();

                                Node<Tiket<int>, int>* node = q->getNode();

                                delete node;

                            } while (!(q->isEmpty()) && !(high == q->r_operations));

                        break;

                    }
        
                break;
            }

            delete q;
        }

    } catch(const std::runtime_error& e) {
        std::cerr << "Something go wrong -> " << e.what() << '\n';
        exit(1);
    }
};