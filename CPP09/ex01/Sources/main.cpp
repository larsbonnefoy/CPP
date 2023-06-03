#include "../Includes/RPN.hpp"
#include <exception>

int main(int ac, char **av){
    if (ac != 2) {
        std::cerr << "Invalid Arguments" << std::endl;
        return (1);
    }
    std::string input(av[1]);
    int result;
    
    try {
        result = RNP(input);
        std::cout << result << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
