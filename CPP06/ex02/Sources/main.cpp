/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:02:21 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/30 10:02:22 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Base.hpp"
#include "../Includes/A.hpp"
#include "../Includes/B.hpp"
#include "../Includes/C.hpp"

Base *generate(void);
void indentify(Base *p);
void indentify(Base &p);

int main(void){
    Base *testPtr = generate();
    Base &rtestPtr = *testPtr;
    indentify(testPtr);
    indentify(rtestPtr);
    delete testPtr;
    return (0);
}
