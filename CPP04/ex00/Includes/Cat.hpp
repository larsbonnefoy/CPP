/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:25:07 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:25:08 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

    public:
        Cat(void);
        Cat(const Cat &other);
        virtual ~Cat(void);
        Cat &operator=(const Cat &other);

        virtual void makeSound(void) const;
};

#endif // !CAT_HPP
