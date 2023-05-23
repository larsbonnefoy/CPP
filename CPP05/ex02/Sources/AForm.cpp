/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:19 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:14:20 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AForm.hpp"
#include "../Includes/Bureaucrat.hpp"
#include <string>
#include <iostream>
//set default value for target
AForm::AForm(void)
    : _name("Random white paper"), _target("Default"),_signed(false), _signGrade(150), _execGrade(150) {
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _target(other._target) ,_signed(false), _signGrade(other._signGrade), _execGrade(other._signGrade) {
}

AForm::~AForm(void) {
}

AForm &AForm::operator=(const AForm &other) {
    (void) other;
    return (*this);
}

std::ostream &operator<<(std::ostream &out,const AForm &f) {
    out << "-----FORM----" << std::endl;
    out << "Name: " << f.getName() << std::endl;
    out << "Signed: " << f.getSigned() << std::endl;
    out << "Signed Grade: " << f.getSignGrade() << std::endl;
    out << "Exec Grade: " << f.getExecGrade() << std::endl;
    return (out);
}

//################MEMBER FUNCTIONS#######################// 
std::string AForm::getName(void) const {
    return (this->_name);
}

int AForm::getSigned(void) const {
    return (this->_signed);
}

int AForm::getSignGrade(void) const {
    return (this->_signGrade);
}

int AForm::getExecGrade(void) const {
    return (this->_execGrade);
}

std::string AForm::getTarget(void) const {
    return (this->_target);
}

void AForm::setTarget(std::string target) {
    this->_target = target;
}

void AForm::execute(Bureaucrat &executor) const {
    if (this->getSigned() == false)
        throw FormNotSignedException();
    else if (this->getExecGrade() < executor.getGrade())
        throw GradeTooLowException();
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade)
        throw GradeTooLowException();
    else if (this->_signed == true)
        throw AlreadySignedException();
    this->_signed = true;
}

//################EXCEPTION#######################// 
const char* AForm::GradeTooLowException::what() const throw() {
    return("[AForm::GradeTooLowException] : Grade too low");
}

const char* AForm::GradeTooHighException::what() const throw() {
    return("[AForm::GradeTooHighException] : Grade too high");
}

const char* AForm::AlreadySignedException::what() const throw() {
    return("[AForm::AlreadySignedException] : Form is alreay signed.");
}

const char* AForm::FormNotSignedException::what() const throw() {
    return("[AForm::FormNotSignedException] : Form is not signed.");
}
