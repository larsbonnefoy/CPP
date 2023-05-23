/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:15:11 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:15:12 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
