/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:28:14 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:28:15 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
    

    public:
        Ice(void);
        Ice(const Ice &other);
        ~Ice(void);
        Ice &operator=(const Ice &other);

        AMateria *clone(void) const;
        void use (ICharacter &target);
}; 

#endif
