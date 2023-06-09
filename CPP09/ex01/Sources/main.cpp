/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:26:16 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/06/09 13:26:17 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/RPN.hpp"
#include <exception>

int main(int ac, char **av){
    if (ac != 2) {
        std::cerr << "Invalid Arguments" << std::endl;
        return (1);
    }
    std::string input(av[1]);
    int result;
    
    try {
        result = RNP(input);
        std::cout << result << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
