/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:01:53 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/30 10:01:54 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Serializer.hpp"
#include "../Includes/Data.hpp"

#include <iostream>

int main(void) {
    Data test(10);
    std::cout << test.getData() << std::endl;

    Data *returnVal;
    uintptr_t ptrTest; 

    //#####################Serialize#################### 
    ptrTest = Serializer::serialize(&test);
    std::cout << ptrTest << std::endl;
    std::cout << &ptrTest << std::endl;
    

    //#####################Deserialize#################### 
    returnVal = Serializer::deserialize(ptrTest);
    std::cout << returnVal->getData() << std::endl;

    return (0);
}
