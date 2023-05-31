/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:11:32 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/31 15:11:33 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Span.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>

Span::Span(void) : _size(0) {
}

Span::Span(unsigned int size) 
    : _size(size) {
}

Span::Span(const Span& other){
    this->_size = other._size;
    this->_vec = other._vec;
}

Span::~Span(void) {
}

Span& Span::operator=(const Span &other) {
    this->_size = other._size;
    this->_vec = other._vec;
    return *this;
}

void Span::addNumber(int nb) {
    if ( _vec.size() == _size ) {
        throw NoSpaceLeftException();
    }
    else {
        _vec.push_back(nb);
    }
}

unsigned int Span::shortestSpan(void) {
    
    unsigned int minSpan = UINT_MAX;

    if (_vec.size() < 2) {
        throw NotEnoughValuesException();
    }

    std::vector<int> sortedVector = _vec;
    sort(sortedVector.begin(), sortedVector.end());
    std::vector<int>::iterator iter;

    for (iter = sortedVector.begin(); iter <  sortedVector.end() - 1; iter++) {
        long long res = static_cast<long long>(*iter) - static_cast<long long>(*(iter + 1));
        if (res < 0) {
            res = res * -1; 
        }
        if (res < minSpan)
            minSpan = static_cast<unsigned int>(res);
    }
    return (minSpan);
}

unsigned int Span::longestSpan(void) {
    if (_vec.size() < 2) {
        throw NotEnoughValuesException();
    }
    std::vector<int>::iterator min = std::min_element(this->_vec.begin(), this->_vec.end());
    std::vector<int>::iterator max = std::max_element(this->_vec.begin(), this->_vec.end());
    return (*max - *min);
}

void Span::fillSpan(std::vector<int>::iterator &beginOther, std::vector<int>::iterator &endOther) {
    unsigned int range = std::distance(beginOther, endOther);
    if (range > this->_size) {
        throw NoSpaceLeftException();
    }
    this->_vec.insert(this->_vec.begin(), beginOther, endOther);
}

const char* Span::NoSpaceLeftException::what() const throw() {
        return("[Span::NoSpaceLeft] : No place left in vector to allocate value.");
}

const char* Span::NotEnoughValuesException::what() const throw() {
        return("[Span::NotEnoughValues] : Not enough values in vector");
}
