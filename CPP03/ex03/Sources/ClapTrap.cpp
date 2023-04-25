/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:06:14 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/04/25 15:06:34 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ClapTrap.hpp"

#include <string>
#include <iostream>

ClapTrap::ClapTrap(void)
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Name Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
    : _name(other._name), _hitPoints(other._hitPoints), 
    _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap Copy Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap Assigment Operator Called" << std::endl;

    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

unsigned int ClapTrap::getHP(void) const {
    return (this->_hitPoints);
}

std::string ClapTrap::getName(void) const {
    return (this->_name);
}

void ClapTrap::attack(const std::string &target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name <<" cannot attack when dead" << std::endl;
    }
    else if (this->_energyPoints == 0) {
        std::cout << this->_name << " cannot attack, no energy points left" << std::endl;
    }
    else {
        std::cout << this->_name << " ClapTrap attacks " << target;
        std::cout << " for " << this->_attackDamage << std::endl; 
        this->_energyPoints -= 1;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name <<" cannot repair when dead" << std::endl;
    }
    else if (this->_energyPoints == 0) {
        std::cout << this->_name << " cannot repair, no energy points left" << std::endl;
    }
    else {
        std::cout << this->_name << " repairs himself for " << amount << std::endl;
        this->_hitPoints += amount;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "Stop beating " << this->_name << " he's already dead" << std::endl;
    }
    else {
        unsigned int maxAmount = amount;
        if (this->_hitPoints < amount) {
            maxAmount = _hitPoints;
        }
        std::cout << this->_name << " takes " << maxAmount << " point of damages"<< std::endl;
        this->_hitPoints -= maxAmount;
    }
}
