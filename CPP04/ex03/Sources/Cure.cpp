/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:29:16 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:29:17 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AMateria.hpp"
#include "../Includes/Cure.hpp"

#include <iostream>

Cure::Cure(void) : AMateria("cure") {
}

Cure::Cure(const Cure &other) {
    *this = other;
}

Cure::~Cure(void) {
}

Cure &Cure::operator=(const Cure &other) {
    this->_type = other._type;
    return (*this);
}

AMateria *Cure::clone(void) const {
    Cure *res = new Cure(*this);
    return (res);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
