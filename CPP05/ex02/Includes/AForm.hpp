#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
class AForm {

    protected:
        const std::string   _name;
        const std::string   _target;
        bool                _signed;
        const int           _signGrade;
        const int           _execGrade;

    public:
        AForm(void);
        AForm(const std::string name, const int signGrade, const int execGrade);
        AForm(const Form &other);
        virtual ~AForm(void);
        Form& operator=(const Form& other);


        //quelle fonction mettre en pure virtual?
        std::string getName(void) const;
        int         getSigned(void) const;
        int         getSignGrade(void) const;
        int         getExecGrade(void) const;
        virtual void        beSigned(Bureaucrat& bureaucrat) = 0;
        virtual void        execute(Bureaucrat& executor) = 0;

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
