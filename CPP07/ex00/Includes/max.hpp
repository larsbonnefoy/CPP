#ifndef MAX_HPP
#define MAX_HPP 

template <typename T>
const T & max(T const &x, T const &y) {
    return ((x > y) ? x : y);
};

#endif
