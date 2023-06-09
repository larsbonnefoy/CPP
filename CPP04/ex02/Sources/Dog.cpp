/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:27:41 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:27:42 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Dog.hpp"

#include <iostream>

Dog::Dog(void) : AAnimal() {
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog Copy constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain(*(other._brain));
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor called" << std::endl;
    delete this->_brain;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog Assigment operator called" << std::endl;
    this->_type = "Dog";
    *this->_brain = *other._brain;
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "BARK BARK" << std::endl;
}

Brain *Dog::getBrain(void) const {
    return (this->_brain);
}
