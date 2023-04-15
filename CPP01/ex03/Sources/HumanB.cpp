#include "../Includes/HumanB.hpp"

#include <iostream>

HumanB::HumanB( std::string name ) : _name(name), _weapon(nullptr) {
}

void HumanB::attack(void) {
    if (this->_weapon == nullptr) {
        std::cout << this->_name << " has no weapon" << std::endl;       
    }
    else {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    }
};

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
};
