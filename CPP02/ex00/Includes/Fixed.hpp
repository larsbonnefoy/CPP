#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {

    private:
        int                 _value; 
        static int const    _bits;

    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
