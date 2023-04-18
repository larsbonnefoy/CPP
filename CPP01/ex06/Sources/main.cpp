#include "../Includes/Harl.hpp"

#include<iostream>

int main(int argc, char **argv) {
    
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int input = 0; 

    if (argc != 2) {
        std::cout << "Unvalid Args" << std::endl;
        return (1);
    };

    std::string input_str = argv[1];
    for (int i = 0; i < 4; i++) {
        if (input_str.compare(options[i]) == 0) {
            input = i + 1;
            break;
        };
    };

    Harl harl;

    harl.complain(input);

    return (0);
};
