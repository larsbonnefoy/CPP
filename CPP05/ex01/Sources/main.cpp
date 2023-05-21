#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Form.hpp"
#include <exception>
#include <iostream>

int main(void){
    std::cout << "============================" << std::endl;
    try {
        Form b("Contract for Remy", 1000, 149);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form b("Contract for Remy", -1111, 149);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form b("Contract for Remy", 50, 1000);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form b("Contract for Remy", 50, -100);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << std::endl << "============================" << std::endl;
        Bureaucrat notAChef("Remy", 150);
        Form b("Contract for Remy", 149, 149);
        std::cout << b << std::endl;
        notAChef.signForm(b);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << std::endl << "============================" << std::endl;
        Bureaucrat chef("Michelle", 1);
        Bureaucrat notAChef("Remy", 150);
        Form b("Contract for Remy", 149, 149);
        std::cout << b << std::endl;
        chef.signForm(b);
        std::cout << std::endl;
        std::cout << b << std::endl;
        chef.signForm(b);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << std::endl << "============================" << std::endl;
        Form randomPaper;
        Form importantPaper("Big Contract", 1, 1);
        Bureaucrat notAChef("Remy", 150);
        notAChef.signForm(randomPaper);
        importantPaper.beSigned(notAChef);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
