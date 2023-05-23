/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:13:58 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:13:59 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
class AForm {

    private:
        const std::string   _name;
        std::string         _target;
        bool                _signed;
        const int           _signGrade;
        const int           _execGrade;

    public:
        AForm(void);
        AForm(const std::string name, const int signGrade, const int execGrade);
        AForm(const AForm &other);
        virtual ~AForm(void);
        AForm& operator=(const AForm& other);

        std::string         getName(void) const;
        int                 getSigned(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        void                setTarget(std::string target);
        std::string         getTarget(void) const;
        void                beSigned(Bureaucrat& bureaucrat);
        virtual void        execute(Bureaucrat& executor) const = 0;

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

        class FormNotSignedException : public std::exception {
            public:
                const char* what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &out,const AForm &b);

#endif
