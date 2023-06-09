/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:25:57 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/06/09 13:26:01 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <exception>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>

void convertValues(std::map<std::string, double> &dataMap, std::string inputFile);
void getDataBase(std::map<std::string, double> &dataMap);

class FileError : public std::exception {
    public:
        const char* what(void) const throw();
};

class DateError : public std::exception {
    public:
        const char* what(void) const throw();
};

class ValueError : public std::exception {
    public:
        const char* what(void) const throw();
};

class FormatError : public std::exception {
    public:
        const char* what(void) const throw();
};

#endif // !BITCOINEXCHANGE_HP
