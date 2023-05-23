/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:13:20 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:13:23 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
