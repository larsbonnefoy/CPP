#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "../Includes/AForm.hpp"
#include<string>
class ShrubberyCreationFrom : public AForm {

    public:
        ShrubberyCreationFrom(void); 
        ShrubberyCreationFrom(std::string target); 
        ShrubberyCreationFrom(const ShrubberyCreationFrom &other); 
        ~ShrubberyCreationFrom(void); 
        ShrubberyCreationFrom& operator=(const ShrubberyCreationFrom& other); 

        
};

#endif
