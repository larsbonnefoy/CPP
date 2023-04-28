#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    
    protected:
        std::string _type;        

    public:
        Animal(void);
        Animal(const Animal &other);
        virtual ~Animal(void);
        Animal &operator=(const Animal &other);

        std::string getType(void) const;

        virtual void makeSound(void) const;
};

#endif
