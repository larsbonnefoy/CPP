/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:26:14 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/06/09 13:26:15 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#define ADD '+'
#define MIN '-'
#define DIV '/'
#define MULT '*'
#define SPACE ' '

#include <iostream>
#include <stack>
#include <sstream>
#include <exception>

class DivisionByZeroError : public std::exception {
    public:
        const char* what(void) const throw();
};


class UnvalidOperatorError : public std::exception {
    public:
        const char* what(void) const throw();
};

class UnvalidStackSizeError : public std::exception {
    public:
        const char* what(void) const throw();
};

class UnvalidCharacterError : public std::exception {
    public:
        const char* what(void) const throw();
};

int RNP(std::string &inputStr);
#endif // !RPN_HPP
