#ifndef INTERN_HPP
#define INTERN_HPP
#include"../Includes/AForm.hpp"

class Intern {
    private:

    public:
        Intern(void);
        Intern(const Intern& other);
        ~Intern(void);
        Intern& operator=(const Intern& other);

        AForm* makeForm(std::string formName, std::string target);

        class UnkownFormException: public std::exception {
            public:
                const char* what(void) const throw();
        };
};

#endif
