#include "../Includes/Zombie.hpp"

Zombie *newZombie( std::string name );
void randomChump( std::string name );

int main(void) {

    Zombie *heapZomb;
    Zombie testZomb("test");

    randomChump("stack");

    heapZomb = newZombie("Heap");
    heapZomb->announce();

    delete heapZomb;
};
