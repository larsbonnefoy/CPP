#include "../Includes/ClapTrap.hpp"

#include <iostream>

int main(void) {

    ClapTrap A("Michel");

    ClapTrap B("Kevin");

    A.attack("Someone");
    B.attack("Someone else");
    A.attack("Someone");
    A.attack("Someone");
    A.attack("Someone");
    A.beRepaired(10);
    std::cout << A.getName() <<" has " << A.getHP() << " HP left" << std::endl;
    A.attack("Someone");
    A.attack("Someone");
    A.attack("Someone");
    A.attack("Someone");
    A.attack("Someone");
    A.attack("Someone");
    A.beRepaired(10);
    B.takeDamage(4);
    std::cout << B.getName() <<" has " << B.getHP() << " HP left" << std::endl;
    B.takeDamage(12);
    std::cout << B.getName() <<" has " << B.getHP() << " HP left" << std::endl;
    B.takeDamage(1);
    B.attack("Someone");
    B.beRepaired(10);
}
