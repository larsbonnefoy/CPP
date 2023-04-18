
#ifndef HARL_HPP
#define HARL_HPP

#include<string>

#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
#define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
#define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define ERROR "This is unacceptable ! I want to speak to the manager now."


class Harl {
    
    private:
        void    (Harl::*_funcPtr[4]) (void) const;
        void    _debug( void ) const;
        void    _info( void ) const;
        void    _warning( void ) const;
        void    _error( void ) const;

    public:
        Harl(void);
        ~Harl(void);
        void complain( int level ) const;
};

#endif
