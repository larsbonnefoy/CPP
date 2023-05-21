#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
class Form {

    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _execGrade;

    public:
        Form(void);
        Form(const std::string name, const int signGrade, const int execGrade);
        Form(const Form &other);
        ~Form(void);
        Form& operator=(const Form& other);

        
        std::string getName(void) const;
        int         getSigned(void) const;
        int         getSignGrade(void) const;
        int         getExecGrade(void) const;
        void        beSigned(Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what(void) const throw();
        };

        class AlreadySignedException : public std::exception {
            public:
                const char* what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &out,const Form &b);

#endif
