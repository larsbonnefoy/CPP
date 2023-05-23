/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:12:32 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/23 13:13:08 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void){
    std::cout << "################COPY and ASSIGNMENT constructors#############" << std::endl;
    Bureaucrat A("A", 100);
    std::cout << A << std::endl;

    Bureaucrat B(A);
    std::cout << B << std::endl;

    Bureaucrat C;
    C = A;
    std::cout << C << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl << std::endl;

    try {
        Bureaucrat chef("Michelle", 2);
        Bureaucrat notAChef("Remy", 149);
        Bureaucrat smallBoy("smallBoy", 1000000);
        Bureaucrat bigBoy("smallBoy", 0); //this line is never read as the above line throws an exception
        std::cout << smallBoy << std::endl; 
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    //std::cout << test << std::endl; //=>impossible d'imprimer ca car pas dans le bloc try catch 
    try {
        Bureaucrat chef("Michelle", 2);
        chef.incrGrade();
        std::cout << chef << std::endl;
        chef.incrGrade();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat notAChef("Remy", 149);
        notAChef.decrGrade();
        std::cout << notAChef << std::endl;
        notAChef.decrGrade();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "################COPY and ASSIGNMENT object destructors###############" << std::endl;
    return (0);
}
