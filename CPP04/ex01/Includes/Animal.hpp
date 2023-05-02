/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:26:27 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:26:28 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

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
        virtual Brain *getBrain(void) const;
};

#endif
