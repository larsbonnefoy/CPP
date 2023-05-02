/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:27:17 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:27:17 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal {
    
    protected:
        std::string _type;        

    public:
        AAnimal(void);
        AAnimal(const AAnimal &other);
        virtual ~AAnimal(void);
        AAnimal &operator=(const AAnimal &other);

        std::string getType(void) const;

        virtual void makeSound(void) const = 0;
        virtual Brain *getBrain(void) const = 0;
};

#endif
