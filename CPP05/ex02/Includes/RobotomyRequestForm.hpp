/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:05 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:14:06 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../Includes/AForm.hpp"
#include<string>
class RobotomyRequestForm : public AForm {

    public:
        RobotomyRequestForm(void); 
        RobotomyRequestForm(std::string target); 
        RobotomyRequestForm(const RobotomyRequestForm &other); 
        ~RobotomyRequestForm(void); 
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other); 

        void execute(Bureaucrat &executor) const ; 

        class FailedRobotomyException : public std::exception {
            public:
                const char* what(void) const throw();
        };
};

#endif
