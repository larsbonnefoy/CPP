#include "../Includes/Point.hpp"
#include "../Includes/Fixed.hpp"

static Fixed ft_abs(Fixed val) {
    if (val < 0) {
        return (val * Fixed(-1));
    }
    return (val);
}

static Fixed CalcTriArea(Point a, Point b, Point c)
{
    Fixed half(2);

    return (ft_abs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / half));
}


bool bsp(Point const a, Point const b, Point const c, Point const point) {

    a.printCoord();
    b.printCoord();
    c.printCoord();
    point.printCoord();

    Fixed totalArea(CalcTriArea(a, b, c));
    Fixed surface1(CalcTriArea(point, b, c));
    Fixed surface2(CalcTriArea(a, point, c));
    Fixed surface3(CalcTriArea(a, b, point));

    std::cout << "Total Area = " << totalArea << std::endl;
    std::cout << "Summ Area = " << surface1 + surface2 + surface3 << std::endl;
    if (surface1 == 0 || surface2 == 0 || surface3 == 0)
        return (0);
    return (totalArea == surface1 + surface2 + surface3);
}
