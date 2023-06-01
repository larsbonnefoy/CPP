#include <algorithm>
#include <exception>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;
  
bool isLeap(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) ||(year % 400 == 0));
}
  
bool isValidDate(int day, int month, int year)
{
    if (year > MAX_VALID_YR || year < MIN_VALID_YR)
        return false;
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
        throw std::exception();
    }
    ss >> delimiter;       // Discard delimiter
    if (ss.fail() || delimiter != '-') {
        throw std::exception();
    }
    ss >> date.tm_mon;     // Extract month
    if (ss.fail()) {
        throw std::exception();
    }
    ss >> delimiter;       // Discard delimiter '-'
    if (ss.fail() || delimiter != '-') {
        throw std::exception();
    }
    ss >> date.tm_mday;    // Extract day
    if (ss.fail()) {
        throw std::exception();
    }
    if (!isValidDate(date.tm_mday, date.tm_mon, date.tm_year)) {
        std::cout << "Unvalid Date" << std::endl;
        throw std::exception();
    }
}

void parseVal(double value) {
    if (value < 0 || value > 1000) {
        throw std::exception();
    }
}

void getDataBase(std::map<std::string, double> &dataMap) {
    std::string line;
    std::ifstream infile;

    infile.open("dataTest.csv", std::ios::in);
    if (!infile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        throw std::exception();
    }
    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string dateString;
        double value;
        
        if (std::getline(ss, dateString, ',') && ss >> value) {
            parseDate(dateString);
            dataMap[dateString] = value;
        }
    }
    infile.close();
}

void convertValues(std::map<std::string, double> &dataMap, std::string inputFile) {
    std::string line;
    std::ifstream infile;
    (void) dataMap;

    infile.open(inputFile, std::ios::in);
    if (!infile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        throw std::exception();
    }
    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string dateString;
        double value;
        std::map<std::string, double>::iterator it;

        if (std::getline(ss, dateString, '|') && ss >> value) {
            try {
                parseDate(dateString); //should check for trailing space, ... here (=> pop_back)
                parseVal(value);
                it = dataMap.find(dateString);
                if (it == dataMap.end()) {
                    std::cout << dateString << ": could not find value" << std::endl;
                }
                else {
                    std::cout << dateString << " => " << value << " = " << std::setprecision(10) << static_cast<double>(it->second)*value << std::endl;
                }
            }
            catch (std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }
        else {
            std::cout << dateString << ": Could not convert Value" << std::endl;
        }
    }
    infile.close();
}

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    std::map<std::string, double> dataMap;

    try {
        getDataBase(dataMap);
        convertValues(dataMap, av[1]);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
