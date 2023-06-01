#include <exception>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>


void printDate(std::tm &date){
    std::cout << date.tm_year + 1900 << "-" << date.tm_mon + 1 << "-" << date.tm_mday;
}

void parseDate(const std::string& dateString) {
    std::tm date = {};
    std::istringstream ss(dateString);
    char delimiter;

    ss >> date.tm_year;    // Extract year
    ss >> delimiter;       // Discard delimiter '-'
    ss >> date.tm_mon;     // Extract month
    ss >> delimiter;       // Discard delimiter '-'
    ss >> date.tm_mday;    // Extract day

    // Adjust values for std::tm structure
    date.tm_year -= 1900;  // Years since 1900
    date.tm_mon -= 1;      // Months are zero-based (0-11)
}

int main(int ac, char **av){
    (void) av;
    if (ac != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    std::string line;
    std::map<std::string, int> dataMap;
    std::ifstream infile;

    infile.open("data.csv", std::ios::in);
    if (!infile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }
    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string dateString;
        int value;

        if (std::getline(ss, dateString, ',') && ss >> value) {
            try {
                parseDate(dateString);
                dataMap[dateString] = value;
            }
            catch (std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    infile.close();
    std::map<std::string, int>::iterator it;
    for (it = dataMap.begin(); it != dataMap.end(); ++it) {
        std::cout << "[" << it->first << "] = " << it->second << std::endl;
    }
    return (0);
}
