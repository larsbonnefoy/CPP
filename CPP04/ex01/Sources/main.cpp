#include "../Includes/Animal.hpp"
#include "../Includes/Cat.hpp"
#include "../Includes/Dog.hpp"
#include "../Includes/Brain.hpp"
#include <cstdlib>

int main(void) {

    std::cout << "=========DEEP COPY============" << std::endl;
    Brain a;

    for (int i = 0; i < 20; i++) {
        a.setIdea("BeepBoop");
    }

    Brain b(a);

    for (int i = 10; i < 20; i++) {
        b.replaceIdea("MEEP", i);
    }

    for (int i = 0; i < 20; i++) {
        std::cout << a.getIdea(i) << std::endl;
        std::cout << b.getIdea(i) << std::endl;
        std::cout << "===========" << std::endl;
    }
    std::cout << "==============================" << std::endl;

    Animal *array[] =  {
        new Cat(),
        new Cat(),
        new Dog(),
        new Dog()
    };

    std::cout << "==============================" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete array[i];
    }
    return (0);
}
