/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:08 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:14:09 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

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
