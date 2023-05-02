/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:27:23 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:27:24 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

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
