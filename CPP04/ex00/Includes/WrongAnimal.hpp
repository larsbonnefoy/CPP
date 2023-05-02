/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:25:14 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:25:15 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
    
    protected:
        std::string _type;        

    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &other);
        ~WrongAnimal(void);
        WrongAnimal &operator=(const WrongAnimal &other);

        std::string getType(void) const;

        void makeSound(void) const;
};

#endif
