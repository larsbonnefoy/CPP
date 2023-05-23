#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "../Includes/AForm.hpp"
#include<string>
class ShrubberyCreationForm : public AForm {

    public:
        ShrubberyCreationForm(void); 
        ShrubberyCreationForm(std::string target); 
        ShrubberyCreationForm(const ShrubberyCreationForm &other); 
        ~ShrubberyCreationForm(void); 
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); 

        void execute(Bureaucrat &executor) const ; 

        class FailedToOpenException : public std::exception {
            public:
                const char* what(void) const throw();
        };
};

#endif
