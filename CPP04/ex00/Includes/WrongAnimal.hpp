#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
    
    protected:
        std::string _type;        

    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &other);
        ~WrongAnimal(void);
        WrongAnimal &operator=(const WrongAnimal &other);

        std::string getType(void) const;

        void makeSound(void) const;
};

#endif
