#include "../Includes/AMateria.hpp"
#include "../Includes/Ice.hpp"

#include <iostream>

Ice::Ice(void) : AMateria("ice") {
}

Ice::Ice(const Ice &other) {
    *this = other;
}

Ice::~Ice(void) {
}

Ice &Ice::operator=(const Ice &other) {
    this->_type = other._type;
    return (*this);
}

AMateria *Ice::clone(void) const {
    Ice *res = new Ice(*this);
    return (res);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
