#include "../Includes/Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _value(0) {
}

Fixed::Fixed(int const val) {
    this->_value = val << this->_bits;
}

Fixed::Fixed(float const val) {
    this->_value = roundf(val * (1 << this->_bits));
}

Fixed::Fixed(const Fixed& other) {
    this->_value = other.getRawBits();
} 

Fixed::~Fixed(void) {
}

Fixed& Fixed::operator=(const Fixed& other){
    if (this != &other) {
        _value = other.getRawBits();
    }
    return (*this);
}

bool    Fixed::operator<(const Fixed& other) const{
    return (this->_value < other._value);
}

bool    Fixed::operator>(const Fixed& other) const{
    return (this->_value > other._value);
}

bool    Fixed::operator<=(const Fixed& other) const{
    return (this->_value <= other._value);
}

bool    Fixed::operator>=(const Fixed& other) const{
    return (this->_value >= other._value);
}

bool    Fixed::operator==(const Fixed& other) const{
    return (this->_value == other._value);
}

bool    Fixed::operator!=(const Fixed& other) const{
    return (this->_value != other._value);
}

Fixed   Fixed::operator+(const Fixed& other) const {
    Fixed ret;
    ret.setRawBits(this->_value + other._value); 
    return (ret);
}

Fixed   Fixed::operator-(const Fixed& other) const {
    Fixed ret;
    ret.setRawBits(this->_value - other._value);
    return (ret);
}

Fixed   Fixed::operator*(const Fixed& other) const {
    Fixed ret;
    ret.setRawBits((this->_value * other._value) >> this->_bits);
    return (ret);
}

Fixed   Fixed::operator/(const Fixed& other) const {
    Fixed ret;
    if (other == 0) {
        std::cout << "Div by 0 not allowed" << std::endl;
        return (0);
    }
    else {
        ret.setRawBits((this->_value  << this->_bits) / other._value);
        return (ret);
    }
}

Fixed   Fixed::operator++(int) {
    Fixed tmp;

    tmp = *this;
    this->_value += 1;
    return (tmp);
}

Fixed&  Fixed::operator++ (void) {
    this->_value += 1;
    return (*this);
}

Fixed   Fixed::operator--(int) {
    Fixed tmp;

    tmp = *this;
    this->_value -= 1;
    return (tmp);
}

Fixed&  Fixed::operator-- (void) {
    this->_value -= 1;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &pt) {
    out << pt.toFloat();
    return (out);
}

int Fixed::getRawBits(void) const {
    return (this->_value);
}

void Fixed::setRawBits(const int raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return ((float)this->_value / (1 << this->_bits));
}

int Fixed::toInt(void) const {
    return (this->_value >> this->_bits);
}

Fixed&  Fixed::min(Fixed& a, Fixed& b) {
    if (a <= b)
        return (a);
    return (b);
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b)  {
    if (a <= b)
        return (a);
    return (b);
}

Fixed&  Fixed::max(Fixed& a, Fixed& b) {
    if (a >= b)
        return (a);
    return (b);
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b)  {
    if (a >= b)
        return (a);
    return (b);
}
