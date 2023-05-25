#include<iostream>
#include<cmath>
#include<limits>

#include"../Includes/ScalarConversion.hpp"

int main(int ac, char **av) {
    (void) av;
    if (ac != 2) {
        std::cout << "Unvalid number of Args." << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
}
