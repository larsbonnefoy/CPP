/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:27:43 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:27:44 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AAnimal.hpp"
#include "../Includes/Cat.hpp"
#include "../Includes/Dog.hpp"
#include "../Includes/Brain.hpp"

int main(void) {

    //AAnimal test;
    std::cout << "=========DEEP COPY============" << std::endl;
    Brain a;

    for (int i = 0; i < 5; i++) {
        a.setIdea("BeepBoop");
    }

    Brain b(a);

    for (int i = 3; i < 5; i++) {
        b.replaceIdea("MEEP", i);
    }

    for (int i = 0; i < 5; i++) {
        std::cout << a.getIdea(i) << std::endl;
        std::cout << b.getIdea(i) << std::endl;
        std::cout << "===========" << std::endl;
    }
    std::cout << "==============================" << std::endl;

    AAnimal *array[] =  {
        new Cat(),
        new Cat(),
        new Dog(),
        new Dog()
    };

    AAnimal *cat = array[0];
    Brain *brainCat = cat->getBrain();
    brainCat->setIdea("Do I go out of in?");
    brainCat->setIdea("MEOMEEOMEOMEOME");
    brainCat->setIdea("EAT EAT EAT");
    std::cout << cat->getType() << ": " << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << cat->getType() << ": " << cat->getBrain()->getIdea(1) << std::endl;
    std::cout << cat->getType() << ": " << cat->getBrain()->getIdea(2) << std::endl;

    AAnimal	*copycat = new Cat(*(Cat *)(array[0]));

    copycat->getBrain()->replaceIdea("NO HUNGRY", 2);

    std::cout << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << cat->getBrain()->getIdea(1) << std::endl;
    std::cout << cat->getBrain()->getIdea(2) << std::endl;
    std::cout << copycat->getBrain()->getIdea(0) << std::endl;
    std::cout << copycat->getBrain()->getIdea(1) << std::endl;
    std::cout << copycat->getBrain()->getIdea(2) << std::endl;

    for (int i = 0; i < 4; i++) {
        delete array[i];
    }
    std::cout << "==============================" << std::endl;
    delete copycat;
    std::cout << "==============================" << std::endl;
    return (0);
} 
