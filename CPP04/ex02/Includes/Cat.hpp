#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

    private:
        Brain *_brain;

    public:
        Cat(void);
        Cat(const Cat &other);
        virtual ~Cat(void);
        Cat &operator=(const Cat &other);
    
        virtual Brain *getBrain(void) const;
        virtual void makeSound(void) const;
};

#endif // !CAT_HPP
