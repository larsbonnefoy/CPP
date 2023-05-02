/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:25:35 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:25:37 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal() {
    std::cout << "WrongCat constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) {
    std::cout << "WrongCat Copy constructor called" << std::endl;
    this->_type = other._type;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    std::cout << "WrongCat Assigment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

void WrongCat::makeSound(void) const {
    std::cout << "GRAOU MIAOU MIAOU" << std::endl;
}
