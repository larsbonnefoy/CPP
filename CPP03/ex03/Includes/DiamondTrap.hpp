/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:05:54 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/04/25 15:05:54 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../Includes/FragTrap.hpp"
#include "../Includes/ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;

    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &other);
        ~DiamondTrap(void);
        DiamondTrap &operator=(const DiamondTrap &other);

        using ScavTrap::attack;

        void    whoAmI(void);

};
#endif
