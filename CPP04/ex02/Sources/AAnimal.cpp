/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:27:30 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:27:30 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AAnimal.hpp"
#include "../Includes/Brain.hpp"

AAnimal::AAnimal(void) : _type("Default"){
    std::cout << "AAnimal Default Constructor Called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
    std::cout << "AAnimal Copy Constructor Called" << std::endl;
}

AAnimal::~AAnimal(void) {
    std::cout << "AAnimal Destructor Called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    std::cout << "AAnimal Assigment operator Called" << std::endl;
    this->_type = other._type;
    return (*this);
}

std::string AAnimal::getType(void) const {
    return (this->_type);
}

void AAnimal::makeSound(void) const {
}

Brain *AAnimal::getBrain(void) const {
    return (NULL);
}
