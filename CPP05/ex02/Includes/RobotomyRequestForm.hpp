#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../Includes/AForm.hpp"
#include<string>
class RobotomyRequestForm : public AForm {

    public:
        RobotomyRequestForm(void); 
        RobotomyRequestForm(std::string target); 
        RobotomyRequestForm(const RobotomyRequestForm &other); 
        ~RobotomyRequestForm(void); 
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other); 

        void execute(Bureaucrat &executor) const ; 

        class FailedRobotomyException : public std::exception {
            public:
                const char* what(void) const throw();
        };
};

#endif
