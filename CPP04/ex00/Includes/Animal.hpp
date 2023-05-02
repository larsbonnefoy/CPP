/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:25:01 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:25:04 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    
    protected:
        std::string _type;        

    public:
        Animal(void);
        Animal(const Animal &other);
        virtual ~Animal(void);
        Animal &operator=(const Animal &other);

        std::string getType(void) const;

        virtual void makeSound(void) const;
};

#endif
