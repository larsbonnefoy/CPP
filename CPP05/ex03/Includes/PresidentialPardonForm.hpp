#ifndef PRESIDENTIALPARDONFORM 
#define PRESIDENTIALPARDONFORM 

#include "../Includes/AForm.hpp"
#include<string>
class PresidentialPardonForm : public AForm {

    public: 
        PresidentialPardonForm(void); 
        PresidentialPardonForm(std::string target); 
        PresidentialPardonForm(const PresidentialPardonForm &other); 
        ~PresidentialPardonForm(void); 
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other); 

        void execute(Bureaucrat &executor) const ; 

};

#endif
