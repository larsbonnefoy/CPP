#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Intern.hpp"
#include "../Includes/AForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

int main(void){
    Intern someIntern;
    Bureaucrat bigboss("BOSS", 1);
    AForm *someForm;
    try {
        someForm = someIntern.makeForm("ShrubberyCreationForm", "Home");
        std::cout << *someForm << std::endl;
        bigboss.signForm(*someForm);
        bigboss.executeForm(*someForm);
        delete someForm;
        someForm = someIntern.makeForm("PresidentialPardonForm", "Michel");
        std::cout << *someForm << std::endl;
        bigboss.signForm(*someForm);
        bigboss.executeForm(*someForm);
        delete someForm;
        someForm = someIntern.makeForm("RobotomyRequestForm", "Michel");
        std::cout << *someForm << std::endl;
        bigboss.signForm(*someForm);
        bigboss.executeForm(*someForm);
        delete someForm;
        someForm = someIntern.makeForm("Unicorn", "Michel");
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
