/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:28:02 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:28:03 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria {
    
    protected:
        std::string _type;

    public:
        AMateria(void);
        AMateria(std::string type);
        AMateria(const AMateria &other);
        virtual ~AMateria(void);
        AMateria &operator=(const AMateria &other);

        std::string const &getType(void) const;
        
        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter &target);
};

#endif
