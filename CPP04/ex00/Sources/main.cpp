#include "../Includes/Animal.hpp"
#include "../Includes/Cat.hpp"
#include "../Includes/Dog.hpp"
#include "../Includes/WrongAnimal.hpp"
#include "../Includes/WrongCat.hpp"

int main(void) {

    std::cout << "============Normal animals========================" << std::endl;
    std::cout << "============Constructors==========================" << std::endl;
    Animal  random;
    Dog     dog;
    Cat     cat;

    std::cout << "==================================================" << std::endl;
    std::cout << random.getType() << ": "; 
    random.makeSound();
    std::cout << dog.getType() << ": "; 
    dog.makeSound();
    std::cout << cat.getType() << ": "; 
    cat.makeSound();


    std::cout << "============Constructors==========================" << std::endl;
    Animal *baseptr;
    Cat     subClass;
    std::cout << "==================================================" << std::endl;
    
    baseptr = &subClass;
    std::cout << baseptr->getType() << ": "; 
    baseptr->makeSound();

    std::cout << "============Constructors==========================" << std::endl;
    const Animal *metaPtr = new Animal();
    const Animal *dogPtr = new Dog();
    const Animal *catPtr = new Cat();
    std::cout << "==================================================" << std::endl;
    std::cout << metaPtr->getType() << ": "; 
    metaPtr->makeSound();
    std::cout << dogPtr->getType() << ": "; 
    dogPtr->makeSound();
    std::cout << catPtr->getType() << ": "; 
    catPtr->makeSound();
    std::cout << "==================================================" << std::endl;
    delete metaPtr;
    delete dogPtr;
    delete catPtr;
    std::cout << "============WRONG animals========================" << std::endl;
    std::cout << "============Constructors==========================" << std::endl;
    WrongAnimal wrongRandom;
    WrongCat wrongCat;
    WrongAnimal *wrongBasePtr;
    WrongCat    wrongSubClass;
    std::cout << "==================================================" << std::endl;
    std::cout << wrongRandom.getType() << ": "; 
    wrongRandom.makeSound();
    std::cout << wrongCat.getType() << ": "; 
    wrongCat.makeSound();

    wrongBasePtr = &wrongSubClass;
    std::cout << wrongBasePtr->getType() << ": "; 
    wrongBasePtr->makeSound();
    std::cout << "==================================================" << std::endl;
    return (0);
}
