#include "../Includes/Fixed.hpp"
#include <iostream>

int main( void ) {

    Fixed a;
    Fixed const b( 11.3f ); 
    Fixed const b_bis( 10 ); 
    Fixed const c( 42.42f ); 
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    Fixed e;

    std::cout << "raw a = " << a.getRawBits() << std::endl;
    std::cout << "raw b = " << b.getRawBits() << std::endl;
    std::cout << "raw c = " << c.getRawBits() << std::endl;
    std::cout << "raw d = " << d.getRawBits() << std::endl;
    
    std::cout << "a is " << a << std::endl;
    std::cout << "a  to int is " << a.toInt() << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
   
    std::cout << "-------------Comparaison operators--------------" << std::endl;
    std::cout << (a < c) << std::endl; 
    std::cout << (a <= b) << std::endl; 
    std::cout << (c > a) << std::endl; 
    std::cout << (a >= b) << std::endl; 
    std::cout << (a == b) << std::endl; 
    std::cout << (b_bis == b) << std::endl; 
    std::cout << (a != b) << std::endl; 
    std::cout << "-------------Arithmetic operators--------------" << std::endl;
    std::cout << b + b << std::endl; 
    std::cout << (b - a) << std::endl; 
    std::cout << (b * b_bis) << std::endl; 
    std::cout << (b_bis / 0) << std::endl; 
    std::cout << (b_bis / b) << std::endl; 
    std::cout << "---------(++)Increment operators--------------" << std::endl;
    std::cout <<"Start a =  " << e << std::endl; 
    std::cout <<"Pre-Incr=  "<< ++e << std::endl; 
    std::cout <<"Start a =  " << e << std::endl; 
    std::cout <<"Post-Inc=  " << e++ << std::endl; 
    std::cout <<"End a   =  " << e << std::endl; 
    std::cout << "---------(--)Increment operators--------------" << std::endl;
    std::cout <<"Start a =  " << e << std::endl; 
    std::cout <<"Pre-Decr=  "<< --e << std::endl; 
    std::cout <<"Start a =  " << e << std::endl; 
    std::cout <<"Post-Dec=  " << e-- << std::endl; 
    std::cout <<"End a   =  " << e << std::endl; 
    std::cout << "-------------MAX/MIN functions--------------" << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    return 0;
}
