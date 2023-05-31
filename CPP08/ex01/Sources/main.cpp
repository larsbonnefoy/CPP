#include "../Includes/Span.hpp"
#include <climits>
#include <exception>
#include <iostream>
#include <limits>

int main(void) {
    std::vector<int> randomVector(20000, 100);
    std::vector<int>::iterator startRandomVector = randomVector.begin();
    std::vector<int>::iterator endRandomVector = randomVector.end();

    std::cout << "----------Random Span---------" << std::endl;
    Span sp(10);
    sp.addNumber(2);
    sp.addNumber(123);
    sp.addNumber(5);
    sp.addNumber(7);
    sp.addNumber(4);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "longest span: "<< sp.longestSpan() << std::endl;
    std::cout << "shortest span:" << sp.shortestSpan() << std::endl << std::endl;

    std::cout << "----------MAX/MIN Span---------" << std::endl;
    Span spanInstance(2);
    spanInstance.addNumber(INT_MIN);
    spanInstance.addNumber(INT_MAX);
    std::cout << "longest span: "<< spanInstance.longestSpan() << std::endl;
    std::cout << "shortest span:" << spanInstance.shortestSpan() << std::endl << std::endl;

    try {
        std::cout << ">>Span Full" << std::endl;
        spanInstance.addNumber(0);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl << std::endl;
    }
    Span spanInstance2(3);
    try {
        std::cout << ">>Not enough values in Span" << std::endl;
        spanInstance2.addNumber(0);
        spanInstance2.longestSpan();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl << std::endl;
    }
    try {
        std::cout << ">>Span to small to fill" << std::endl;
        spanInstance.fillSpan(startRandomVector, endRandomVector);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl << std::endl;
    }

    std::cout << "----------bigSpan---------" << std::endl;
    Span bigSpan(30000);
    bigSpan.fillSpan(startRandomVector, endRandomVector);
    std::cout << "longest span: " << bigSpan.longestSpan() << std::endl;
    std::cout << "shortest span: "<< bigSpan.shortestSpan() << std::endl;

    return (0);
}
