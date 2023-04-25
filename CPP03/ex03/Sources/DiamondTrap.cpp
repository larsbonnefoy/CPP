/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:06:16 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/04/25 15:06:33 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(void) : ClapTrap() {
    std::cout << "Diamond Trap constructor called" << std::endl;

    ClapTrap::_name = "Default_clap_name";
    this->_name = "Default Diamond";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 50;
    std::cout << this->_name << " HP : " << this->_hitPoints << std::endl;
    std::cout << this->_name << " EP : " << this->_energyPoints << std::endl;
    std::cout << this->_name << " AD : " << this->_attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
    std::cout << "DiamondTrap name constructor called" << std::endl;

    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    std::cout << this->_name << " HP : " << this->_hitPoints << std::endl;
    std::cout << this->_name << " EP : " << this->_energyPoints << std::endl;
    std::cout << this->_name << " AD : " << this->_attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "Diamond Trap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
    std::cout << "DiamondTrap Copy Constructor Called" << std::endl;

        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DiamondTrap Copy Assignment Constructor Called" << std::endl;

    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

void    DiamondTrap::whoAmI(void) {
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
    std::cout << "DiamondTrap name: " << this->_name << std::endl;
}
