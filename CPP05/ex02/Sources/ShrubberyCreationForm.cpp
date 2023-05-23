/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:56 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:25:24 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137) {
    this->setTarget("Default");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137) {
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm("ShrubberyCreationForm", 145, 137) {
    this->setTarget(other.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    this->setTarget(other.getTarget());
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat &executor) const {
    this->AForm::execute(executor);
    std::ofstream output(this->getTarget() + "_shrubbery");
    if (!output.is_open()) {
        throw FailedToOpenException();
    }
    output << "       _-_" << std::endl;
	output << "    /~~   ~~\\" << std::endl;
	output << " /~~         ~~\\" << std::endl;
	output << "{               }" << std::endl;
	output << " \\  _-     -_  /" << std::endl;
	output << "   ~  \\\\ //  ~" << std::endl;
	output << "_- -   | | _- _" << std::endl;
	output << "  _ -  | |   -_" << std::endl;
	output << "      // \\\\" << std::endl;
	output.close();
}

const char* ShrubberyCreationForm::FailedToOpenException::what() const throw() {
    return("[ShrubberyCreationForm] : Could not open File");
}
