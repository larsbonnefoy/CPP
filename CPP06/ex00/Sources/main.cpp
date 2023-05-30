/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:01:36 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/30 10:01:37 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<cmath>
#include<limits>

#include"../Includes/ScalarConversion.hpp"

int main(int ac, char **av) {
    (void) av;
    if (ac != 2) {
        std::cout << "Unvalid number of Args." << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
}
