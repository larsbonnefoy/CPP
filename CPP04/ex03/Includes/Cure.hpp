#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
    

    public:
        Cure(void);
        Cure(const Cure &other);
        ~Cure(void);
        Cure &operator=(const Cure &other);

        AMateria *clone(void) const;
        void use (ICharacter &target);
}; 

#endif
