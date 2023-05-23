#include "../Includes/RobotomyRequestForm.hpp"
#include <exception>
#include <random>
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45) {
    this->setTarget("Default");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45) {
    this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) {
    *this = other; 
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    this->setTarget(other.getTarget());
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat &executor) const {
    this->AForm::execute(executor);
    std::cout << "BZBZBBZBBZBBZBZBSBRBRBBBB (some drilling noises)" << std::endl;
    std::random_device rd;  // Seed the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dis(0, 1); // Range of values: 0 or 1

    int result = dis(gen); // Generate random value: 0 or 1

    if (result == 0) {
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    } else {
        throw FailedRobotomyException();
    }
}

const char* RobotomyRequestForm::FailedRobotomyException::what() const throw() {
    return("[RobotomyRequestForm] : Failed Robotomy");
}
