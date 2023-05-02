/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:25:10 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:25:12 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

    public:
        Dog(void);
        Dog(const Dog &other);
        virtual ~Dog(void);
        Dog &operator=(const Dog &other);

        virtual void makeSound(void) const;
};

#endif // !DOG_HPP
