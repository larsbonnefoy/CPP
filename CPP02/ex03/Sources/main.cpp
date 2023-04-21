#include "../Includes/Fixed.hpp"
#include "../Includes/Point.hpp"
#include <iostream>


bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {

    Point a;
    std::cout << "Default constructor" << std::endl;
    std::cout << "x = " << a.getX() << std::endl;
    std::cout << "y = " << a.getY() << std::endl;
    std::cout << "Float constructor" << std::endl;
    Point b(2.5f, 1.25);
    std::cout << "x = " << b.getX() << std::endl;
    std::cout << "y = " << b.getY() << std::endl;
    a = b;
    std::cout << "Copy constructor" << std::endl;
    std::cout << "x = " << a.getX() << std::endl;
    std::cout << "y = " << a.getY() << std::endl;

    Point x(0, 0);
    Point y(0, 1);
    Point z(1, 0);
    Point in(0.25, 0.25);
    Point out(-1, -1);
    std::cout << "--------First-------" << std::endl;
    std::cout << bsp(x, y, z, in) << std::endl;
    std::cout << "--------Second-------" << std::endl;
    std::cout << bsp(x, y, z, out) << std::endl;
}
