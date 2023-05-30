/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:06:40 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/30 14:06:55 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Iter.hpp"
#include <iostream>
#include <string>

int main(void) {
    int intArray[5] = {0, 1 , 23, 532, -12};
    iter(intArray, 5, displayContent<int>);

    char charArray[5] = {'A', 'B', 'C', 'D', 'E'};
    
    iter(charArray, 5, displayContent<char>);

    return (0);
};