/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:12:28 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:13:06 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Bureaucrat.hpp"
#include<string>
#include<exception>
#include<iostream>

Bureaucrat::Bureaucrat(void)
    : _name("Default"), _grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name) {
    std::cout << "Full Constructor of " << name << " Called" << std::endl;
    if (grade > 150) {
        throw GradeTooLowException();
    }
    else if (grade < 1) {
        throw GradeTooHighException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    this->_grade = other._grade;
    return *this;
}

std::ostream &operator<<(std::ostream &out,const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (out);
}

//################MEMBER FUNC#######################// 
std::string Bureaucrat::getName(void) const {
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

void Bureaucrat::incrGrade(void) {
    if (--this->_grade < 1) {
        throw GradeTooHighException();
    }
}

void Bureaucrat::decrGrade(void) {
    if (++this->_grade > 150) {
        throw GradeTooLowException();
    }
}

//################EXCEPTION#######################// 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return("[Bureaucrat::GradeTooLowException] : Cannot assign grade lower than 150.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return("[Bureaucrat::GradeTooHighException] : Cannot assign grade higher than 1.");
}
