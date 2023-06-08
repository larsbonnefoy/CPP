#include "../Includes/MergeInsert.hpp"
#include <algorithm>
#include <iterator>
#include <sys/time.h>

int main(int ac, char **av) {
    std::vector<int> vec, vecSorted;
    std::deque<int> deq, deqSorted;
    std::list<int> lst, lstSorted;
    struct timeval vecBegin, vecEnd, listBegin, listEnd, deqBegin, deqEnd;

    try {
        if (ac < 2) {
            throw InvalidValueError();
        }
        parseInput(av, vec, lst, deq);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
//    gettimeofday(&deqBegin, 0);
    std::cout << "========START========" << std::endl;
    std::cout << "FULL : ";
    printCont(deq);
    deqSorted =  mergeInsert(deq);
    std::cout << "========AFTER SORT========" << std::endl;
    printCont(deqSorted);
    std::cout << "Is deque sorted : " <<  std::is_sorted(deqSorted.begin(), deqSorted.end()) << std::endl;
    std::deque<int>::iterator it = std::is_sorted_until(deqSorted.begin(), deqSorted.end());
    std::cout << *it << std::endl;
    std::cout << "distance = " <<std::distance(deqSorted.begin(), it) << std::endl;
//    gettimeofday(&deqEnd, 0);
/*
    gettimeofday(&listBegin, 0);
    //lstSorted = mergeInsert(lst);
    gettimeofday(&listEnd, 0);

    gettimeofday(&vecBegin, 0);
    vecSorted = mergeInsert(vec);
    gettimeofday(&vecEnd, 0);

    std::cout << "Before: ";
    printCont(vec);
    std::cout << "After: ";
    printCont(vecSorted);
    std::cout << "=======DEQ==========" << std::endl;
    std::cout << "Time to process a range of 5 elements with std::deque: " << elapsed(deqBegin, deqEnd) << "us" << std::endl;
    std::cout << "Is deque sorted : " <<  std::is_sorted(deqSorted.begin(), deqSorted.end()) << std::endl;
    std::deque<int>::iterator it = std::is_sorted_until(deqSorted.begin(), deqSorted.end());
    std::cout << *it << std::endl;
    std::cout << "distance = " <<std::distance(deqSorted.begin(), it) << std::endl;
    std::cout << "distance = " <<std::distance(deqSorted.begin(), deqSorted.end()) << std::endl;
    std::cout << "=======LST==========" << std::endl;
    std::cout << "Time to process a range of 5 elements with std::list: " << elapsed(listBegin, listEnd) << "us" <<std::endl;
    std::cout << "Is list sorted : " <<  std::is_sorted(lstSorted.begin(), lstSorted.end()) << std::endl;
    std::cout << "=======VEC==========" << std::endl;
    std::cout << "Time to process a range of 5 elements with std::vec: " << elapsed(vecBegin, vecEnd) << "us" << std::endl;
    std::cout << "Is list sorted : " <<  std::is_sorted(vecSorted.begin(), vecSorted.end()) << std::endl;
*/
    return (0);
}
