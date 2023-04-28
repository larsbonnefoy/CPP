#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal {
    
    protected:
        std::string _type;        

    public:
        AAnimal(void);
        AAnimal(const AAnimal &other);
        virtual ~AAnimal(void);
        AAnimal &operator=(const AAnimal &other);

        std::string getType(void) const;

        virtual void makeSound(void) const = 0;
        virtual Brain *getBrain(void) const = 0;
};

#endif
