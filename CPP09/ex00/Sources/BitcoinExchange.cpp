/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:25:49 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/06/09 13:26:04 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/BitcoinExchange.hpp"
#include <iterator>

bool isLeap(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) ||(year % 400 == 0));
}
  
bool isValidDate(int day, int month, int year)
{
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (month == 2)
    {
        if (isLeap(year))
            return (day <= 29);
        else
            return (day <= 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);
    return true;
}

void parseDate(std::string& dateString) {
    
    dateString.erase(remove(dateString.begin(), dateString.end(), ' '), dateString.end());
    std::istringstream ss(dateString);
    std::tm date = {};
    char delimiter;

    ss >> date.tm_year;    // Extract Years
    if (ss.fail()) {
        throw DateError();
    }
    ss >> delimiter;       // Discard delimiter
    if (ss.fail() || delimiter != '-') {
        throw DateError();
    }
    ss >> date.tm_mon;     // Extract month
    if (ss.fail()) {
        throw DateError();
    }
    ss >> delimiter;       // Discard delimiter '-'
    if (ss.fail() || delimiter != '-') {
        throw DateError();
    }
    ss >> date.tm_mday;    // Extract day
    if (ss.fail()) {
        throw DateError();
    }
    if (!isValidDate(date.tm_mday, date.tm_mon, date.tm_year)) {
        throw DateError();
    }
}

void parseVal(double value) {
    if (value < 0 || value > 1000) {
        throw ValueError();
    }
}

void getDataBase(std::map<std::string, double> &dataMap) {
    std::string line;
    std::ifstream infile;

    infile.open("data.csv", std::ios::in);
    if (!infile.is_open()) {
        throw FileError();
    }
    while (std::getline(infile, line)) {
        if (line.find("date") != std::string::npos) {
            continue;
        }
        std::istringstream ss(line);
        std::string dateString;
        double value = 0;
        
        if (std::getline(ss, dateString, ',') && ss >> value) {
            try {
                parseDate(dateString);
                dataMap[dateString] = value;
            }
            catch (std::exception &e) {
                std::cout << dateString << "\t--> " << e.what() << std::endl;
            }
        }
        else {
            std::cout << dateString << "\t--> "<< FormatError().what() << std::endl;
        }
    }
    infile.close();
}

void convertValues(std::map<std::string, double> &dataMap, std::string inputFile) {
    std::string line;
    std::ifstream infile;

    infile.open(inputFile, std::ios::in);
    if (!infile.is_open()) {
        throw FileError();
    }
    while (std::getline(infile, line)) {
        if (line.find("date") != std::string::npos) {
            continue;
        }
        std::istringstream ss(line);
        std::string dateString;
        double value = 0;
        std::map<std::string, double>::iterator it;

        if (std::getline(ss, dateString, '|') && ss >> value) {
            try {
                parseDate(dateString);
                parseVal(value);
                if (dateString < dataMap.begin()->first) {
                    throw DateError();
                }
                it = dataMap.find(dateString);
                if (it != dataMap.end()) {
                    std::cout << dateString << " => " << value << " = ";
                    std::cout << std::setprecision(10) << static_cast<double>(it->second)*value << std::endl;
                }
                else {
                    it = dataMap.lower_bound(dateString);
                    if (it != dataMap.end()) {
                        std::cout << dateString << " => " << value << " = ";
                        std::cout << std::setprecision(10) << static_cast<double>(it->second)*value << std::endl;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout << dateString << " => " << value << "\t--> ";
                std::cout << e.what() << std::endl;
            }
        }
        else {
            std::cout << dateString << "\t--> "<< FormatError().what() << std::endl;
        }
    }
    infile.close();
}

/*###################ERRORS#############################*/
const char *FileError::what(void) const throw() {
    return ("[FileError] : Could not open or read from file");
}

const char *DateError::what(void) const throw() {
    return ("[DateError] : Unvalid Date");
}

const char *ValueError::what(void) const throw() {
    return ("[ValueError] : Value too high or too low");
}

const char *FormatError::what(void) const throw() {
    return ("[FormatError] : Unvalid Format");
}
