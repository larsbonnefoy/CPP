/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:06:22 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/04/25 15:11:47 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ClapTrap.hpp"
#include "../Includes/ScavTrap.hpp"
#include "../Includes/FragTrap.hpp"
#include "../Includes/DiamondTrap.hpp"

#include <iostream>

int main(void) {

    ClapTrap *baseclass;

    DiamondTrap didi("didi");
    baseclass = &didi;
    baseclass->attack("TEST1");

    didi.attack("TEST2");
    didi.beRepaired(50);
    std::cout <<didi.getName()<< " has " << didi.getHP() << " HP left"<< std::endl;
    didi.takeDamage(200);
    std::cout <<didi.getName()<< " has " << didi.getHP() << " HP left"<< std::endl;
    didi.takeDamage(1);
    didi.highFivesGuys();
    didi.guardGate();
    didi.whoAmI();

    return (0);
}
