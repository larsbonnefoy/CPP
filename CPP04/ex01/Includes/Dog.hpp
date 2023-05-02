/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:26:39 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:26:39 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

    private:
        Brain *_brain;

    public:
        Dog(void);
        Dog(const Dog &other);
        virtual ~Dog(void);
        Dog &operator=(const Dog &other);

        virtual void makeSound(void) const;
        virtual Brain *getBrain(void) const;
};

#endif // !DOG_HPP
