/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:29:20 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:29:20 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AMateria.hpp"
#include "../Includes/Ice.hpp"

#include <iostream>

Ice::Ice(void) : AMateria("ice") {
}

Ice::Ice(const Ice &other) {
    *this = other;
}

Ice::~Ice(void) {
}

Ice &Ice::operator=(const Ice &other) {
    this->_type = other._type;
    return (*this);
}

AMateria *Ice::clone(void) const {
    Ice *res = new Ice(*this);
    return (res);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
