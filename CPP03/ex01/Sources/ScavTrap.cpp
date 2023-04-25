#include "../Includes/ScavTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap(void) : ClapTrap() {
    std::cout << "ScavTrap Default Construtor Called" << std::endl;

    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap Name Construtor Called" << std::endl;

    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
    std::cout << "ScavTrap Copy Constructor Called" << std::endl;

        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap Copy Assignment Constructor Called" << std::endl;

    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

void ScavTrap::attack(const std::string &target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name <<" cannot attack when dead" << std::endl;
    }
    else if (this->_energyPoints == 0) {
        std::cout << this->_name << " cannot attack, no energy points left" << std::endl;
    }
    else {
        std::cout << this->_name << " ScavTrap attacks " << target;
        std::cout << " for " << this->_attackDamage << std::endl; 
        this->_energyPoints -= 1;
    }
}

void ScavTrap::guardGate(void) {
    std::cout << this->getName() << " is now in Gate keeper mode" << std::endl;
}
