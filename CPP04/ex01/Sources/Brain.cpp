/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:26:49 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:26:50 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Brain.hpp"
#include <iostream>

Brain::Brain(void) {
    std::cout << "Brain default constructor Called" << std::endl;
    for (int i = 0; i < 100; i++){
        _ideas[i] = "";
    }
} 

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor Called" << std::endl;
    for (int i = 0; i < 100; i ++) {
        this->_ideas[i] = other._ideas[i];
    }
}

Brain::~Brain(void) {
    std::cout << "Brain destructor Called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << "Brain copy operator Called" << std::endl;
    for (int i = 0; i < 100; i ++) {
        this->_ideas[i] = other._ideas[i];
    }
    return (*this);
}

std::string Brain::getIdea(int index) const {
    
    if (index > 99 || index < 0) {
        return ("Unvalid index");
    }
    else if (this->_ideas[index].empty()) {
        return ("...");
    }
    else {
        return (this->_ideas[index]);
    }
}

void Brain::setIdea(std::string idea) {
    if (idea.empty()) {
        return ;
    }
    else {
        int i = 0;
        while (this->_ideas[i] != "" && i < 100) {
            i++;
        } 
        if (i == 100) {
            std::cout << "No space left to think" << std::endl;
            return ;
        }
        else {
            this->_ideas[i] = idea;
        }
    }
}

void Brain::replaceIdea(std::string idea,  int index) {
    if (idea.empty()) {
        return ;
    }
    else {
        if (index < 0 || index > 99) {
            std::cout << "Unvalid index" << std::endl;
            return ;
        }
        else {
            this->_ideas[index] = idea;
        }
    }
}
