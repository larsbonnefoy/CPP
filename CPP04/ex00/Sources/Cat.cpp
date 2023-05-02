/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:25:26 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:25:44 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal() {
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat Copy constructor called" << std::endl;
    this->_type = other._type;
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat Assigment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "GRAOU MIAOU MIAOU" << std::endl;
}
