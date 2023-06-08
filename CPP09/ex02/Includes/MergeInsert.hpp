#ifndef MERGE_HPP
#define MERGE_HPP

#include <algorithm>
#include <sstream>
#include <sys/wait.h>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <deque>

class InvalidValueError : public std::exception {
    public:
        const char* what(void) const throw();
};

class DuplicateValueError : public std::exception {
    public:
        const char* what(void) const throw();
};

void parseInput(char **av, std::vector<int> &vec, std::list<int> &lst, std::deque<int> &deq);

double elapsed(struct timeval begin, struct timeval	end);

template<typename T>
void printCont(T &cont) {
    std::cout << "Len = " << cont.size() << std::endl;

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
  
    (void) cont;
    T rhs(begin, mid);
    T lhs(mid, end);

    Iterator insertPos = begin;

    Iterator leftIt = lhs.begin();

    Iterator rightIt = rhs.begin();

    while (leftIt != lhs.end() && rightIt != rhs.end()) {
        if (*leftIt < *rightIt) {
            *insertPos = *leftIt;
            leftIt++;
            insertPos++;
            *insertPos = *leftIt;
            leftIt++;
        }
        else {
            *insertPos = *rightIt;
            rightIt++;
            insertPos++;
            *insertPos = *rightIt;
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
}

template<typename T, typename Iterator>
void mergeSort(T &cont, Iterator begin, Iterator end) {

    if (std::distance(begin, end) < 3)
        return;
    
    int distance = std::distance(begin, end)/2; 
    
    if (distance % 2 == 1)
        distance += 1;

    Iterator mid = std::next(begin, distance);

    mergeSort(cont, begin, mid);
    mergeSort(cont, mid, end);
    merge(cont, begin, mid, end);
}

template <typename Iterator>
void pairUp(Iterator begin, Iterator end) {

    Iterator it = begin;
    
    while (it != end) {
        if (*it < *(std::next(it, 1))) {
            std::swap(*it, *(std::next(it, 1)));
        }
        it = std::next(it, 2);
    }
}

template <typename T>
void splitCont(T &cont, T&main, T&pend) {
    typename T::iterator it = cont.begin();
    typename T::iterator ite = cont.end();

    for (; it != ite; it++) {
        if (std::distance(cont.begin(), it) % 2 == 0) {
            main.push_back(*it); 
        }
        else {
            pend.push_back(*it); 
        }
    }
}

template <typename T>
T getJNumber(T nb)
{
    if (nb == 0)
        return 0;
    else if (nb == 1)
        return 1;
    return (getJNumber(nb - 1) + 2 * getJNumber(nb - 2));
}

template <typename T>
void insert(T &main, T&pend) {

    unsigned int maxSize = pend.size();
    unsigned int indexJ = 2;
    unsigned int jn = getJNumber(indexJ);
    unsigned int jn_1 = getJNumber(indexJ - 1);
    unsigned int jn_2 = getJNumber(indexJ - 2);

    typename T::iterator itPendStart = pend.begin();
    typename T::iterator itPendEnd = pend.begin();

    typename T::iterator itInsertPos = main.begin();

    unsigned int insertedAmount = 0;

    while (jn <= maxSize) {

        if (jn == 1) {
            main.insert(main.begin(), *itPendStart);
            insertedAmount++;
        }
        else { 
            std::advance(itPendEnd, jn_1 - jn_2);
            std::advance(itPendStart, jn - jn_1);
            
            typename T::iterator tmpIt = itPendStart;
            while (tmpIt != itPendEnd) {

                //Really not optimal for lists as it goes through the whole list all the time.
                typename T::iterator itMainEnd = main.begin();
                std::advance(itMainEnd, jn + insertedAmount + 1);
                itInsertPos = std::lower_bound(main.begin(), itMainEnd, *tmpIt);
                main.insert(itInsertPos, *tmpIt);
                insertedAmount++;
                tmpIt--;
            }
        }
        indexJ++;
        jn_2 = jn_1;
        jn_1 = jn;
        jn = getJNumber(indexJ);
    }
    if (++itPendStart != pend.end()) {
        while (itPendStart != pend.end()) {
            itInsertPos = std::lower_bound(main.begin(), main.end(), *itPendStart);
            main.insert(itInsertPos, *itPendStart);
            itPendStart++;
        }
    }
}

template<typename T>
T mergeInsert(T &cont) {
   
    bool trailing = false;
    int trailingVal = 0;
    T main;
    T pend;

    if (cont.size() % 2 == 1) {
        trailingVal = cont.back();
        trailing = true;
        cont.pop_back();
    }
    pairUp(cont.begin(), cont.end());
    mergeSort(cont, cont.begin(), cont.end());
    splitCont(cont, main, pend);
    if (trailing == true) {
        pend.push_back(trailingVal);
    }
    insert(main, pend);
    return (main);
}

#endif // !MERGE_HPP
