/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:05:41 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/04/25 15:05:41 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ClapTrap.hpp"
#include "../Includes/FragTrap.hpp"

#include <iostream>

int main(void) {

    ClapTrap clap("ClapClap");
    FragTrap frag("FragFrag");

    std::cout << clap.getName() << " has " << clap.getHP() << " HP" << std::endl;
    std::cout << frag.getName() << " has " << frag.getHP() << " HP" << std::endl;
    clap.attack("Someone");
    frag.attack("Someone else");
    frag.beRepaired(50);
    std::cout << frag.getName() << " has " << frag.getHP() << " HP" << std::endl;
    frag.takeDamage(160);
    std::cout << frag.getName() << " has " << frag.getHP() << " HP" << std::endl;
    frag.attack("Someone");
    frag.takeDamage(1);
    frag.highFivesGuys();
    //clap.highFivesGuys(); -> doesnt work
}
