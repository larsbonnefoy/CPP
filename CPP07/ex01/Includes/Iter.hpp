/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:06:35 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/30 14:06:37 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void displayContent(T &content) {
    std::cout << "Content = " << content << std::endl;
}

template <typename T>
void iter(T array[], int size, void (*f)(T &)) {
    for (int i = 0; i < size; i++) {
        f(array[i]);
    }
}

#endif
