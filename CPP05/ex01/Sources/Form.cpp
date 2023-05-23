/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:13:32 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:13:33 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Form.hpp"
#include "../Includes/Bureaucrat.hpp"
#include <string>
#include <iostream>
Form::Form(void)
    : _name("Random white paper"), _signed(false), _signGrade(150), _execGrade(150) {
}

Form::Form(const std::string name, const int signGrade, const int execGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

Form::Form(const Form &other)
    : _name(other._name), _signed(false), _signGrade(other._signGrade), _execGrade(other._signGrade) {
}

Form::~Form(void) {
}

Form &Form::operator=(const Form &other) {
    (void) other;
    return (*this);
}

std::ostream &operator<<(std::ostream &out,const Form &f) {
    out << "-----FORM----" << std::endl;
    out << "Name: " << f.getName() << std::endl;
    out << "Signed: " << f.getSigned() << std::endl;
    out << "Signed Grade: " << f.getSignGrade() << std::endl;
    out << "Exec Grade: " << f.getExecGrade() << std::endl;
    return (out);
}

//################MEMBER FUNCTIONS#######################// 
std::string Form::getName(void) const {
    return (this->_name);
}

int Form::getSigned(void) const {
    return (this->_signed);
}

int Form::getSignGrade(void) const {
    return (this->_signGrade);
}

int Form::getExecGrade(void) const {
    return (this->_execGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade)
        throw GradeTooLowException();
    else if (this->_signed == true)
        throw AlreadySignedException();
    this->_signed = true;
}
//################EXCEPTION#######################// 

const char* Form::GradeTooLowException::what() const throw() {
    return("[Form::GradeTooLowException] : Grade too low");
}

const char* Form::GradeTooHighException::what() const throw() {
    return("[Form::GradeTooHighException] : Grade too high");
}

const char* Form::AlreadySignedException::what() const throw() {
    return("[Form::AlreadySignedException] : Form is alreay signed.");
}
