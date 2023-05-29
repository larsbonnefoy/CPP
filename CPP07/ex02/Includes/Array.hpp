#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <iostream>

template<typename T>
class Array {
    private:
        unsigned _size; //catch neg value? (or will not compile??)
        T *_array;

    public:
        Array(void);
        Array(int n);
        Array(const Array<T>& other); //specifier le type? (bizarre de copier deux arrays de type diff)
        ~Array(void);
        Array<T>& operator=(const Array<T>& other);
        T& operator[](unsigned int);

        unsigned int size(void);

        class UnvalidAcces : public std::exception {
            public:
                const char * what(void) const throw();
        };
};

template<typename T>
Array<T>::Array(void) : _size(0), _array(nullptr){
}

//set to default value, what if type has not default '0' val, null ?
template<typename T>
Array<T>::Array(int n) : _size(n) {
    _array = new T[n];
}

template<typename T>
Array<T>::Array(const Array<T>& other) {
    this->_size = other._size;
    _array = new T[other._size];
    for (unsigned int i = 0; i < _size; i++) {
        this->_array[i] = other._array[i];
    }
}

template<typename T>
Array<T>::~Array(void) {
    delete[] _array;
}

template<typename T>
Array<T> & Array<T>::operator=(const Array &other) {
    delete[] this->_array;
    this->_size = other._size;
    this->_array = new T[other._size];
    for (unsigned int i = 0; i < _size; i++) {
        this->_array[i] = other._array[i];
    }
    return *this;
}

template<typename T> 
T & Array<T>::operator[](unsigned int index) {
    if (index > _size - 1) {
        throw UnvalidAcces();
    }
    else {
        return(this->_array[index]);
    }
}

template<typename T>
unsigned int Array<T>::size(void) {
    return (_size);
}

template<typename T>
const char* Array<T>::UnvalidAcces::what() const throw() {
    return("[UnvalidAccesException] : Element in Array does not exist");
}

#endif
