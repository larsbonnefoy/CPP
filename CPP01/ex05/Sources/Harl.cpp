#include "../Includes/Harl.hpp"

#include <iostream>


Harl::Harl(void) {
    std::cout << "Constructor called" << std::endl;
    this->_funcPtr[0] = &Harl::_debug;
    this->_funcPtr[1] = &Harl::_info;
    this->_funcPtr[2] = &Harl::_warning;
    this->_funcPtr[3] = &Harl::_error;
};

Harl::~Harl(void) {
    std::cout << "Destructor called" << std::endl;
};

void Harl::_debug( void ) const {
    std::cout << DEBUG << std::endl;
};

void Harl::_info( void )  const {
    std::cout << INFO << std::endl;
};

void Harl::_warning( void ) const {
    std::cout << WARNING << std::endl;
};

void Harl::_error( void ) const {
    std::cout << ERROR << std::endl;
};

void Harl::complain( std::string level ) const {
   
    bool print_error = true;
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (level.compare(options[i]) == 0 ){
            (this->*_funcPtr[i])();
            print_error = 0;
            break;
        };
    };
    if (print_error) {
        std::cout << "Unvalid level of error" << std::endl;
    };
};
