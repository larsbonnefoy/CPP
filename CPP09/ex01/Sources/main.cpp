#include "../Includes/RPN.hpp"
#include <iostream>
#include <sstream>

//format d d op d op d op,... => soit chiffre soit espace soit operande
int main(int ac, char **av){

    if (ac != 2) {
        std::cout << "Invalid Arguments" << std::endl;
    }

    std::stack<int> stack;
    int i = 0;
    char *rpnStr = av[1];
    int topVal;

    while (rpnStr[i]) {
        while (rpnStr[i] == SPACE)    
            i++;
        if (isdigit(rpnStr[i])) {
            std::stringstream ss(rpnStr + i);
            int digit;

            ss >> digit; 
            if (stack.size() < 2 && (digit >= 0 && digit <= 9 )) {
                stack.push(digit);
            }
            else {
                std::cerr << "Error" << std::endl;
                return (1);
            }
        }
        switch (rpnStr[i]) {
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
                    std::cerr << "Error" << std::endl;
                    return (1);
                }
                stack.pop();
                stack.top() /= topVal;            
                break;
            default:
                std::cerr << "Error" << std::endl;
                return (1);
        }
        i++;
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else {
        std::cerr << "Error" << std::endl;
    }
    return (0);
}
