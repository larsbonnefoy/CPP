#include "../Includes/Character.hpp"
#include "../Includes/ICharacter.hpp"
#include "../Includes/Cure.hpp"
#include "../Includes/Ice.hpp"
#include "../Includes/AMateria.hpp"
#include "../Includes/MateriaSource.hpp"
#include "../Includes/IMateriaSource.hpp"
#include <algorithm>

int main(void) {

    IMateriaSource *src = new MateriaSource();

    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria *tmp;
    AMateria *dropedDown;
    
    tmp = src->createMateria("fire");
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    dropedDown = tmp; //->saving dropped weapon in a tmp var
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

    ICharacter *bob = new Character("bob"); 
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->unequip(2);

    std::cout << "=======Copy test=======" << std::endl;
    ICharacter *copyme = new Character(*(Character *)me);
    copyme->use(0, *bob);
    copyme->use(1, *bob);
    copyme->use(2, *bob);
    //problem: cannot get ptr of materia of a copied class as no function is defined in Iterface => unequiping a materia form a copied class will create a leak;
    copyme->unequip(1);
    //copied char cannont use the materia anymore
    copyme->use(1, *bob);
    std::cout << "default character can still use its materia: " << std::endl;
    me->use(1, *bob);
    
    delete bob; 
    delete me; 
    delete copyme;
    delete src;
    delete dropedDown;
    return 0;
}
