#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Form.hpp"
#include<string>
#include<exception>
#include<iostream>

Bureaucrat::Bureaucrat(void)
    : _name("Default"), _grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name) {
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

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e){
        std::cout << this->getName() << " couldn't sign " << form.getName();
        std::cout << " because "<< e.what() << std::endl;
    }
}

//################EXCEPTION#######################// 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return("[Bureaucrat::GradeTooLowException] : Cannot assign grade lower than 150.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return("[Bureaucrat::GradeTooHighException] : Cannot assign grade higher than 1.");
}
