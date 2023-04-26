#include "../Includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Default WRONG animal") {
    std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "WrongAnimal Assigment operator Called" << std::endl;
    this->_type = other._type;
    return (*this);
}

std::string WrongAnimal::getType(void) const {
    return (this->_type);    
}

void WrongAnimal::makeSound(void) const {
    std::cout << "*MEEPMOOP* (Definitely not an animal sound)" << std::endl;
}
