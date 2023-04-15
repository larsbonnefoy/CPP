#include "../Includes/Zombie.hpp"

#define N 4

Zombie* zombieHorde( int nb, std::string name );

int main(void) {

    Zombie *horde;    
    
    horde = zombieHorde(N, "Michel");
    
    for(int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return (0);
};
