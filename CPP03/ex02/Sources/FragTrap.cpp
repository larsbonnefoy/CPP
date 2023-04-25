#include "../Includes/FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << "FragTrap Default Construtor Called" << std::endl;

    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap Name Construtor Called" << std::endl;

    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
    std::cout << "FragTrap Copy Constructor Called" << std::endl;

        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap Copy Assignment Constructor Called" << std::endl;

    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

void FragTrap::highFivesGuys(void) {
    std::cout << this->getName() << " tries a high five" << std::endl;
}
