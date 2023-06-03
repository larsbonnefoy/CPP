#include "../Includes/BitcoinExchange.hpp"
  
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
