/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:15:27 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:15:28 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Intern.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include <exception>

Intern::Intern(void){
}

Intern::Intern(const Intern& other) {
    (void) other;
}

Intern::~Intern(void){
}

Intern& Intern::operator=(const Intern& other){
    (void) other;
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string forms[3] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
    int formType = -1;
    for (int i = 0; i < 3; i++) {
        if (formName.compare(forms[i]) == 0)
            formType = i;
    }
    switch (formType) {
        case 0:
            return(new PresidentialPardonForm(target)); 
        case 1:
            return(new ShrubberyCreationForm(target)); 
        case 2:
            return(new RobotomyRequestForm(target)); 
        default:
            throw UnkownFormException();
    }
}

const char* Intern::UnkownFormException::what(void) const throw(){
    return ("[UnkownFormException] : Unvalid Form");

}
