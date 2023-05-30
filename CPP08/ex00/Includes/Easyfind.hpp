#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception {
    const char* what() const throw() {
        return ("[ValueNotFoundException] : Value not in container");
    }
};

template<typename T>
void easyfind(T const &container, int const &toFind){
    typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);

    if (it == container.end())
        throw ValueNotFoundException();
    else {
        std::cout << "Value " << toFind << " found." << std::endl;
    }
}

#endif // !EASYFIND_HPP
