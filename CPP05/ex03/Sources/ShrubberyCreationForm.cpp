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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) {
    *this = other; 
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
