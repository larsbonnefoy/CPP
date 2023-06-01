/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:11:19 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/31 15:11:20 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Easyfind.hpp"
#include <exception>
#include <vector>
#include <list>
#include <array>

int main(void){
    std::cout << "----------Vector------------" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }
    try {
        easyfind(vec, 4);
        easyfind(vec, 8);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------List------------" << std::endl;
    std::list<int> listCont;
    for (int i = 0; i < 5; i++) {
        listCont.push_back(i);
    }
    try {
        easyfind(listCont, 4);
        easyfind(listCont, 8);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
