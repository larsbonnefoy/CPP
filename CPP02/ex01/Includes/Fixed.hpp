#ifndef FIXED_HPP
#define FIXED_HPP

#include<iostream>
#include <ostream>

class Fixed {

    private:
        int                 _value; 
        static int const    _bits = 8;

    public:
        Fixed(void);
        Fixed(int const val);
        Fixed(float const val);
        Fixed(const Fixed& other);
        ~Fixed(void);
        Fixed   &operator=(const Fixed& other);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &pt);
#endif
