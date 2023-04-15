
#include "../Includes/Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name ) : _name(name) {
    std::cout << this->_name << " constructor called" << std::endl;
};

Zombie::Zombie( void ) : _name("Default") {
    std::cout << this->_name << " constructor called" << std::endl;
};

Zombie::~Zombie(void) {
    std::cout << this->_name  << " destructor called" << std::endl;
};

void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
};

void Zombie::setName(std::string name) {
    this->_name = name;
};
