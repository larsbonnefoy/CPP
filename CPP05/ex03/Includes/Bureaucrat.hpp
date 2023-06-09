/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:15:09 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:15:10 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <string>

class AForm;

class Bureaucrat {

    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat(void);
        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName(void) const;
        int         getGrade(void) const;
        void        incrGrade(void);
        void        decrGrade(void);
        void        signForm(AForm &form);
        void        executeForm(AForm const &form);

        class GradeTooHighException : public std::exception {
            public:
                const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &out,const Bureaucrat &b);

#endif
