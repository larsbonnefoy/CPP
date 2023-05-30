/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:07:35 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/30 14:07:36 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Array.hpp"
#include "../Includes/Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>
#define MAX_VAL 20
int main(void) {
    Array<int> intArray(5); 
    for (int i = 0; i < 5; i++) {
        std::cout << intArray[i] << std::endl;
    }
    Array<char> charArray(5); 
    for (int i = 0; i < 5; i++) {
        std::cout << charArray[i] << std::endl;
    }
    Array<Bureaucrat> arrayBurr(5); 
    for (int i = 0; i < 5; i++) {
        std::cout << arrayBurr[i] << std::endl;
    }
//####################################################################################//
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 10;
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    std::cout << "__________COPY CONSTRUCTOR_______________" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        for (int i = 0; i < MAX_VAL; i++) {
            std::cout << "Original: " << tmp[i] << " | Copy: "<< test[i]<< std::endl;
        }
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "__________ASSIGNMENT OPERATOR_______________" << std::endl;
    Array<int> numbersCopy;
    numbersCopy = numbers;
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "Original: " << numbers[i] << " | Assignment Copy: "<< numbersCopy[i]<< std::endl;
    }
    std::cout << "__________DEEP COPY_______________" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbersCopy[i] = rand() % 10;
        std::cout << "Original: " << numbers[i] << " | Changed Copy: "<< numbersCopy[i]<< std::endl;
    }
    delete [] mirror;
    return 0;
}
