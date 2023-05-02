/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:25:17 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:25:18 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:
        WrongCat(void);
        WrongCat(const WrongCat &other);
        ~WrongCat(void);
        WrongCat &operator=(const WrongCat &other);

        void makeSound(void) const;
};

#endif // !WRONGCAT_HPP
