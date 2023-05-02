/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:25:29 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:25:43 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog Copy constructor called" << std::endl;
    this->_type = other._type;
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog Assigment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "BARK BARK" << std::endl;
}
