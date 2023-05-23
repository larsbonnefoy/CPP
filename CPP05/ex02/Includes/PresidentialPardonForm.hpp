/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:03 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:14:04 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

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
