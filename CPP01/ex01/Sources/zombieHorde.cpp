#include "../Includes/Zombie.hpp"

Zombie* zombieHorde( int nb, std::string name ) {

    Zombie *horde;

    horde = new Zombie[nb];
    for (int i = 0; i < nb; i++) {
        horde[i].setName(name);
    };
    return (horde);
};
