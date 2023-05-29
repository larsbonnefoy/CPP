#include "../Includes/Iter.hpp"
#include <iostream>
#include <string>

int main(void) {
    int intArray[5] = {0, 1 , 23, 532, -12};
    iter(intArray, 5, displayContent<int>);

    char charArray[5] = {'A', 'B', 'C', 'D', 'E'};
    
    iter(charArray, 5, displayContent<char>);

    return (0);
};
