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
    this->_brain = new Brain(*(other._brain));
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor called" << std::endl;
    delete this->_brain;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog Assigment operator called" << std::endl;
    this->_type = other._type;
    *this->_brain = *other._brain;
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "BARK BARK" << std::endl;
}

Brain *Dog::getBrain(void) const {
    return (this->_brain);
}
