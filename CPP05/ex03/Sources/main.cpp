#include "../Includes/Bureaucrat.hpp"
#include "../Includes/AForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

int main(void){
    Bureaucrat bigBoss("BIGBOSS", 1);
    Bureaucrat employe1("Garreth", 139);
    Bureaucrat employe2("Hugo", 50);
    Bureaucrat employe3("Lars", 20);
    std::cout << "===========Copy and assigment operators==========" << std::endl;
    ShrubberyCreationForm def;
    std::cout << def;
    std::cout << def.getTarget() << std::endl;
    ShrubberyCreationForm test("House");
    std::cout << test;
    std::cout << test.getTarget() << std::endl;
    ShrubberyCreationForm test2(test);
    std::cout << test2;
    std::cout << test2.getTarget() << std::endl;
    ShrubberyCreationForm test3;
    test3 = test2;
    std::cout << test3;
    std::cout << test3.getTarget() << std::endl;
    std::cout << "================SHRUB============================" << std::endl;
    std::cout << test;
    std::cout << test.getTarget() << std::endl;
    employe1.executeForm(test);
    bigBoss.executeForm(test);
    employe1.signAForm(test);
    employe1.executeForm(test);
    bigBoss.executeForm(test);
    std::cout << "================ROBOTOMY============================" << std::endl;
    RobotomyRequestForm robot("Michel");
    std::cout << robot;
    std::cout << robot.getTarget() << std::endl;
    employe2.executeForm(robot);
    bigBoss.executeForm(robot);
    employe2.signAForm(robot);
    bigBoss.signAForm(robot);
    employe2.executeForm(robot);
    bigBoss.executeForm(robot);
    std::cout << "================PRESIDENT============================" << std::endl;
    PresidentialPardonForm prisoner("Robert");
    std::cout << prisoner;
    std::cout << prisoner.getTarget() << std::endl;
    //prisoner.execute(bigBoss); ->will crash if not in try catch block !
    employe3.executeForm(prisoner);
    bigBoss.executeForm(prisoner);
    employe3.signAForm(prisoner);
    bigBoss.signAForm(prisoner);
    employe3.executeForm(prisoner);
    bigBoss.executeForm(prisoner);
    
    return (0);
}
