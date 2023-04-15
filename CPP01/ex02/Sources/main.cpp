#include <iostream>
#include <string>

int main(void) {

    std::string str;
    std::string *stringPTR;


    str = "HI THIS IS BRAIN";
    stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory address of str var:    "<< &str << std::endl;
    std::cout << "Memory address of stringPTR:  " << stringPTR << std::endl;
    std::cout << "Memory address of stringREF:  " << &stringREF << std::endl;

    std::cout << "Value of str var:     " << str << std::endl;
    std::cout << "Value of stringPTR:   " << *stringPTR << std::endl;
    std::cout << "Value of stringREF:   " << stringREF << std::endl;
    return (0);
}
