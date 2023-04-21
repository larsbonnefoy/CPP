#include "../Includes/Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::~Point(void){
}

//est ce que ca marche vrmt comme ca ou y a moyen de faire plus clean?
//  -> Aucune idee de comment ca marche mais nice;
Point::Point(const float x, const float y) {
    this->_x = x;
    this->_y = y;
};

Point::Point(const Point &other) {
    this->_x = other.getX(); 
    this->_y = other.getY(); 
}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
        this->_x = other.getX();
        this->_y = other.getY();
    }
    return (*this);
}

Fixed Point::getX(void) const {
    return (this->_x);
}

Fixed Point::getY(void) const {
    return (this->_y);
}

void Point::printCoord() const {
    std::cout << "(" << this->getX() << "," << this->getY() << ")" << std::endl;
}
