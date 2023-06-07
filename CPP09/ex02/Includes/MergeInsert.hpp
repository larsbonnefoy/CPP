#ifndef MERGE_HPP
#define MERGE_HPP
#include <iterator>
#include <utility>
#include <iostream>
#include<vector>
#include<deque>

template<typename T>
void printCont(T &cont) {
    for (typename T::iterator it = cont.begin(); it != cont.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Iterator>
void printSpan(Iterator begin, Iterator end) {
    std::cout << "[";
    for (Iterator it = begin; it != end; it++) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

template<typename T, typename Iterator>
void merge(T &cont, Iterator begin, Iterator mid, Iterator end) {
  
    /*
    (void) cont;
    std::cout << "========================" << std::endl;
    std::cout << "Span" << std::endl;
    printSpan(begin, end);

    int leftSize = std::distance(begin, mid);
    std::cout << "Left size dist = " << leftSize << "- ";
    printSpan(begin, mid);

    int rightSize = std::distance(mid, end);
    std::cout << "right size dist = " << rightSize << "- ";
    printSpan(mid, end);
*/
    (void) cont;
    T rhs;
    T lhs;
    
    for (Iterator it = begin; it != mid ; it++) {
        lhs.push_back(*(it));
    }
    std::cout << "left tmp" << std::endl;
    printCont(lhs);

    for (Iterator it = mid; it != end ; it++) {
        rhs.push_back(*(it));
    }
    std::cout << "right tmp" << std::endl;
    printCont(rhs);

    Iterator insertPos = begin;

    Iterator leftIt = lhs.begin();

    Iterator rightIt = rhs.begin();

    while (leftIt != lhs.end() && rightIt != rhs.end()) {
        if (*leftIt < *rightIt) {
            *insertPos = *leftIt;
            std::cout << "inserted val = " << *leftIt << std::endl;
            leftIt++;
        }
        else {
            *insertPos = *rightIt;
            std::cout << "inserted val = " << *rightIt << std::endl;
            rightIt++;
        }
        insertPos++;
    }
    while (leftIt != lhs.end()) {
        *insertPos = *leftIt;
        leftIt++; 
        insertPos++;
    }
    while (rightIt != rhs.end()) {
        *insertPos = *rightIt;
        rightIt++; 
        insertPos++;
    }
    std::cout << "Merged Container" << std::endl;
    printSpan(begin, end);
    std::cout << "--------------------" << std::endl;
}

template<typename T, typename Iterator>
void mergeSort(T &cont, Iterator begin, Iterator end) {

    int distance = std::distance(begin, end)/2; 
    if (distance % 2 == 1)
        distance += 1;

    Iterator mid = begin + distance;

    std::cout << "[";
    for (Iterator it = begin; it != end; it++) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;

    if (std::distance(begin, end) < 3)
        return;

    mergeSort(cont, begin, mid);
    mergeSort(cont, mid, end);
    merge(cont, begin, mid, end);
}

template <typename Iterator>
void pairUp(Iterator begin, Iterator end) {

    Iterator it = begin;
    
    while (it != end) {
        if (*it < *(it + 1)) {
            std::swap(*it, *(it + 1));
        }
        it += 2;
    }
}

template<typename T>
void mergeInsert(T &cont) {
   
    int trailingVal = 0;
    printCont(cont);
    if (cont.size() % 2 == 1) {
        trailingVal = cont.back();
        cont.pop_back();
        std::cout << trailingVal << std::endl;
    }
    pairUp(cont.begin(), cont.end());
    mergeSort(cont, cont.begin(), cont.end());
    printCont(cont);
}

#endif // !MERGE_HPP
