/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:29:11 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:29:12 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AMateria.hpp"

#include <string>
#include <iostream>

AMateria::AMateria(void) : _type("Default") {
}

AMateria::AMateria(std::string type) : _type(type) {
}

AMateria::AMateria(const AMateria &other) : _type(other._type){
}

AMateria::~AMateria(void) {
}

AMateria &AMateria::operator=(const AMateria &other) {
    this->_type = other._type;
    return (*this);
}

std::string const &AMateria::getType(void) const {
    return(this->_type);
}

void AMateria::use(ICharacter &target) {
    (void) target;
    std::cout << "SHOULD NOT BE USED" << std::endl;
}
