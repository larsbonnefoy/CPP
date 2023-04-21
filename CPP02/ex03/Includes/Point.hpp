#ifndef POINT_HPP
#define POINT_HPP

#include "../Includes/Fixed.hpp"

class Point {
    private:
        Fixed _x; 
        Fixed _y; 

    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point &other);
        ~Point(void);
        Point   &operator=(const Point &other);

        Fixed   getX(void) const;
        Fixed   getY(void) const;
        void    printCoord(void) const;
};

#endif // !POINT_HPP
