#include "../Includes/Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const val) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = val << this->_bits;
}

//overflows and neg values??
Fixed::Fixed(float const val) {
    std::cout << "Float constructor called" << std::endl;

    this->_value = roundf(val * (1 << this->_bits));

/* --> cette methode n'arrondit pas correctement ??
    float int_part;
    float decimal_part = std::modf(val, &int_part);
    int scale_factor = 1 << this->_bits;;
    int fixed_decimal = static_cast<int>(decimal_part * scale_factor);

    this->_value = (static_cast<int>(int_part) << this->_bits) + fixed_decimal;
*/
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    _value = other.getRawBits();
} 

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &pt) {
    out << pt.toFloat();
    return (out);
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(const int raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return ((float)this->_value / (1 << this->_bits));
}

//pb avec les nb negatifs qui round up vers le bas?
int Fixed::toInt(void) const {
    return (this->_value >> this->_bits);
}
