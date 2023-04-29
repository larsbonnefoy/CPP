#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#include <iostream>
#include <string>

class MateriaSource : public IMateriaSource {
    private:
        AMateria *_source[4];

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &other);
        ~MateriaSource(void);
        MateriaSource &operator=(const MateriaSource &other);

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
        
};
#endif
