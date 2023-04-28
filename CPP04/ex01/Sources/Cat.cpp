#include "../Includes/Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal() {
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat Copy constructor called" << std::endl;
    this->_type = other._type;
    this->_brain = new Brain(*(other._brain));
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor called" << std::endl;
    delete this->_brain;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat Assigment operator called" << std::endl;
    this->_type = other._type;
    *this->_brain = *other._brain;
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "GRAOU MIAOU MIAOU" << std::endl;
}

Brain *Cat::getBrain(void) const {
    return (this->_brain);
}
