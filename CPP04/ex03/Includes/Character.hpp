#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {

    private:
        std::string const _name;
        AMateria *_inventory[4];

    public:
        Character(void);
        Character(std::string name);
        Character(const Character &other);
        ~Character(void);
        Character &operator=(const Character &other); 

        std::string const &getName(void) const;
        AMateria *getMateria(int idx) const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif
