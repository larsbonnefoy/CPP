/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:29:13 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:29:14 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Character.hpp"

#include <iostream>

Character::Character(void) : _name("Default") {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = nullptr;
    }
}

Character::Character(std::string name) : _name(name) {
//    std::cout << "Parametric Constructor Called" << std::endl;
    for (int i = 0; i < 4; i++) {
        _inventory[i] = nullptr;
    }
}

Character::Character(const Character &other) : _name(other._name) {
 //   std::cout << "Copy Constructor Called" << std::endl;
    for (int i=0; i < 4; i++) {
        if (other._inventory[i]) {
            this->_inventory[i] = other._inventory[i]->clone();
        } 
        else {
            this->_inventory[i] = nullptr;
        }
    }
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++) {
        delete this->_inventory[i];
    }
}

Character &Character::operator=(const Character &other) {
    for (int i = 0; i < 4; i++) {
        delete this->_inventory[i];
        if (other._inventory[i]) {
            this->_inventory[i] = other._inventory[i]->clone();
        }
        else {
            this->_inventory[i] = nullptr; 
        }
    }
    return (*this);
}

std::string const &Character::getName(void) const {
    return (this->_name);
}

AMateria *Character::getMateria(int idx) const {
    if (idx >= 0 && idx <= 3) {
        return (this->_inventory[idx]);
    }
    return (nullptr);
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == nullptr) {
            this->_inventory[i] = m; 
            return ;
        }
    }
    delete m;
    std::cout << "Inventory Full" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "Unvalid inventory slot" << std::endl;
    }
    else if (_inventory[idx] == nullptr) {
        std::cout << "Empty inventory slot" << std::endl;
    }
    else {
        std::cout << this->getName() << " has unequiped " << _inventory[idx]->getType() << std::endl;
        this->_inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter &target) {
    if ((idx >= 0 && idx <= 3) && _inventory[idx]) {
        _inventory[idx]->use(target);
    }
    else {
        std::cout << "Unable to use Materia" << std::endl;
    }
}
