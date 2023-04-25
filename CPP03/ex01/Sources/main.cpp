/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:05:00 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/04/25 15:05:01 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ClapTrap.hpp"
#include "../Includes/ScavTrap.hpp"

#include <iostream>

int main(void) {

    ClapTrap clap("ClapClap");
    ScavTrap scav("ScavScav");
    
    std::cout << "==================" << std::endl;
    ClapTrap *bsptr;
    ScavTrap derived;
    
    bsptr = &derived;
    bsptr->attack("TEST");
    std::cout << "==================" << std::endl;

    std::cout << clap.getName() << " has " << clap.getHP() << " HP" << std::endl;
    std::cout << scav.getName() << " has " << scav.getHP() << " HP" << std::endl;
    clap.attack("Someone");
    scav.attack("Someone else");
    scav.beRepaired(50);
    std::cout << scav.getName() << " has " << scav.getHP() << " HP" << std::endl;
    scav.takeDamage(160);
    std::cout << scav.getName() << " has " << scav.getHP() << " HP" << std::endl;
    scav.attack("Someone");
    scav.takeDamage(1);
    scav.guardGate();
    //clap.guardGate(); -> doesnt work
}
