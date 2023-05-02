/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:27:21 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:27:22 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

    private:
        Brain *_brain;

    public:
        Cat(void);
        Cat(const Cat &other);
        virtual ~Cat(void);
        Cat &operator=(const Cat &other);
    
        virtual Brain *getBrain(void) const;
        virtual void makeSound(void) const;
};

#endif // !CAT_HPP
