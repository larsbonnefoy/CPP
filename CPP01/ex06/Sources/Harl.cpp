#include "../Includes/Harl.hpp"

#include <iostream>

Harl::Harl(void) {
    this->_funcPtr[0] = &Harl::_debug;
    this->_funcPtr[1] = &Harl::_info;
    this->_funcPtr[2] = &Harl::_warning;
    this->_funcPtr[3] = &Harl::_error;
};

Harl::~Harl(void) {
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

void Harl::complain( int level ) const {

    switch (level) {
        case 1:
            std::cout << "[DEBUG]" << std::endl;
            (this->*_funcPtr[0])();
            std::cout << std::endl;
        case 2:
            std::cout << "[INFO]" << std::endl;
            (this->*_funcPtr[1])();
            std::cout << std::endl;
        case 3:
            std::cout << "[WARNING]" << std::endl;
            (this->*_funcPtr[2])();
            std::cout << std::endl;
        case 4:
            std::cout << "[ERROR]" << std::endl;
            (this->*_funcPtr[3])();
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
};
