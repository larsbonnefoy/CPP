/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:25:52 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/06/09 13:25:53 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/BitcoinExchange.hpp"
  
int main(int ac, char **av){
    if (ac != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    std::map<std::string, double> dataMap;

    try {
        getDataBase(dataMap);
        convertValues(dataMap, av[1]);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
