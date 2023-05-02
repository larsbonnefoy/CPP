/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:28:08 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:28:08 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
    

    public:
        Cure(void);
        Cure(const Cure &other);
        ~Cure(void);
        Cure &operator=(const Cure &other);

        AMateria *clone(void) const;
        void use (ICharacter &target);
}; 

#endif
