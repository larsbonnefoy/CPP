#include "../Includes/Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog Copy constructor called" << std::endl;
    this->_type = other._type;
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor called" << std::endl;
    delete this->_brain;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog Assigment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "BARK BARK" << std::endl;
}
