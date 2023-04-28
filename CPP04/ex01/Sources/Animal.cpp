#include "../Includes/Animal.hpp"

Animal::Animal(void) : _type("Default"){
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal::~Animal(void) {
    std::cout << "Animal Destructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal Assigment operator Called" << std::endl;
    this->_type = other._type;
    return (*this);
}

std::string Animal::getType(void) const {
    return (this->_type);
}

void Animal::makeSound(void) const {
    std::cout << "*Random Animal Noises*" << std::endl;
}
