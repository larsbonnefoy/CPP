/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:29:22 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:29:23 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Character.hpp"
#include "../Includes/ICharacter.hpp"
#include "../Includes/Cure.hpp"
#include "../Includes/Ice.hpp"
#include "../Includes/AMateria.hpp"
#include "../Includes/MateriaSource.hpp"
#include "../Includes/IMateriaSource.hpp"

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
    me->use(-1, *bob);
    me->use(0, *bob);
    me->use(2, *bob);
    me->use(1, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->unequip(-1);
    me->unequip(2);
    me->unequip(2);
    me->use(2, *bob);

    std::cout << "=======Copy test=======" << std::endl;
    ICharacter *copyme = new Character(*(Character *)me);
    AMateria *dropedDown2;
    copyme->use(0, *bob);
    copyme->use(1, *bob);
    copyme->use(2, *bob); //not working as it has been copied from previous char
    copyme->use(3, *bob);
    dropedDown2 = ((Character *)copyme)->getMateria(1);
    copyme->unequip(1);
    //copied char cannont use the materia anymore
    copyme->use(1, *bob);
    std::cout << "default character can still use its materia: ";
    me->use(1, *bob);
    
    delete bob; 
    delete me; 
    delete copyme;
    delete src;
    delete dropedDown;
    delete dropedDown2;
    return 0;
}
