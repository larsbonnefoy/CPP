/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:49 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:29:49 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/PresidentialPardonForm.hpp"
#include <exception>
#include <random>
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {
    this->setTarget("Default");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5) {
    this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm("PresidentialPardonForm", 25, 5) {
    this->setTarget(other.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    this->setTarget(other.getTarget());
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat &executor) const {
    this->AForm::execute(executor);
    std::cout << this->getTarget() << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}
