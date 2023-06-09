/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:26:18 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/06/09 13:26:19 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/RPN.hpp"

int RNP(std::string &inputStr){
    std::stack<int> stack;
    int topVal = 0;

    for (int i = 0; inputStr[i]; i++) {
        if (isdigit(inputStr[i])) 
                stack.push(inputStr[i] - '0');
        else if (inputStr[i] == SPACE)
            continue;
        else {
            if (stack.size() < 2)
                throw UnvalidStackSizeError();
            switch (inputStr[i]) {
                case ADD:
                    topVal = stack.top();
                    stack.pop();
                    stack.top() += topVal;            
                    break;
                case MIN:
                    topVal = stack.top();
                    stack.pop();
                    stack.top() -= topVal;            
                    break;
                case MULT:
                    topVal = stack.top();
                    stack.pop();
                    stack.top() *= topVal;            
                    break;
                case DIV:
                    topVal = stack.top();
                    if (topVal == 0) {
                        throw DivisionByZeroError();
                    }
                    stack.pop();
                    stack.top() /= topVal;            
                    break;
                default:
                    throw UnvalidCharacterError(); 
            }
        }
    }
    if (stack.size() != 1) 
        throw UnvalidStackSizeError();
    return (stack.top());
}

const char* DivisionByZeroError::what() const throw() {
    return ("[DivisionByZeroError] : Impossible to devide by 0");
}

const char* UnvalidStackSizeError::what() const throw() {
    return ("[UnvalidStackSizeError] : Too many operands on the stack");
}

const char* UnvalidCharacterError::what() const throw() {
    return ("[UnvalidCharacterError] : Unvalid character in input");
};

const char* UnvalidOperatorError::what() const throw() {
    return ("[OperatorError] : Unvalid operation");
}
