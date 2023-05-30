/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:01:51 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/30 10:01:52 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../Includes/Data.hpp"

Data::Data(void) : _randomInt(0) {
}

Data::Data(int randomData) : _randomInt(randomData) {
}

Data::Data(const Data &other) : _randomInt(other._randomInt) {
}

Data::~Data(void){
}

Data& Data::operator=(const Data &other) {
    this->_randomInt = other._randomInt;
    return (*this);
}

void Data::setData(int randomData) {
    this->_randomInt = randomData;
}

int Data::getData(void) {
    return (this->_randomInt);
}
