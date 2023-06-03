#include "../Includes/RPN.hpp"

int RNP(std::string &inputStr){
    std::stack<int> stack;
    int topVal = 0;

    for (int i = 0; inputStr[i]; i++) {
        if (isdigit(inputStr[i])) 
                stack.push(inputStr[i] - '0');
        else if (inputStr[i] == SPACE)
            continue;
        else {
            switch (inputStr[i]) {
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
                        throw DivisionByZeroError();
                    }
                    stack.pop();
                    stack.top() /= topVal;            
                    break;
                default:
                    throw UnvalidCharacterError(); 
            }
        }
    }
    if (stack.size() != 1) 
        throw UnvalidStackSizeError();
    return (stack.top());
}

const char* DivisionByZeroError::what() const throw() {
    return ("[DivisionByZeroError] : Impossible to devide by 0");
}

const char* UnvalidStackSizeError::what() const throw() {
    return ("[UnvalidStackSizeError] : Too many operands on the stack");
}

const char* UnvalidCharacterError::what() const throw() {
    return ("[UnvalidCharacterError] : Unvalid character in input");
};
