/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:29:25 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/06/08 16:29:26 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/PmergeMe.hpp"
#include <sys/time.h>

int main(int ac, char **av) {
    std::vector<int> vec, vecSorted, vecSTL;
    std::deque<int> deq, deqSorted, deqSTL;
    std::list<int> lst, lstSorted, lstSTL;
    struct timeval vecBegin, vecEnd, listBegin, listEnd, deqBegin, deqEnd, vecSTLBegin, vecSTLEnd, deqSTLBegin, deqSTLEnd, lstSTLBegin, lstSTLEnd;
    struct timeval dataBegin, dataEnd;

    gettimeofday(&dataBegin, 0);
    try {
        if (ac < 2) {
            throw InvalidValueError();
        }
        parseInput(av, vec, lst, deq);
        vecSTL = vec;
        lstSTL = lst;
        deqSTL = deq;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
    gettimeofday(&dataEnd, 0);

    std::cout << "Before: ";
    printCont(vec);

    gettimeofday(&deqBegin, 0);
    deqSorted =  mergeInsert(deq);
    gettimeofday(&deqEnd, 0);
    
    gettimeofday(&listBegin, 0);
    lstSorted = mergeInsert(lst);
    gettimeofday(&listEnd, 0);

    gettimeofday(&vecBegin, 0);
    vecSorted = mergeInsert(vec);
    gettimeofday(&vecEnd, 0);

/*------------------------------------STL-------------------------------------*/
    gettimeofday(&vecSTLBegin, 0);
    std::sort(vecSTL.begin(), vecSTL.end());
    gettimeofday(&vecSTLEnd, 0);

    gettimeofday(&deqSTLBegin, 0);
    std::sort(deqSTL.begin(), deqSTL.end());
    gettimeofday(&deqSTLEnd, 0);

    gettimeofday(&lstSTLBegin, 0);
    lstSTL.sort();
    gettimeofday(&lstSTLEnd, 0);
/*------------------------------------STL-------------------------------------*/

    std::cout << "After: ";
    printCont(vecSorted);
    std::cout << std::endl << "Time to process Data " << elapsed(dataBegin, dataEnd) << "us" << std::endl << std::endl;
    std::cout << "=======DEQ==========" << std::endl;
    std::cout << "Time to process a range of "<< deq.size() <<" elements with std::deque: " << elapsed(deqBegin, deqEnd) << "us" << std::endl;
    std::cout << "Is deque sorted : " <<  std::is_sorted(deqSorted.begin(), deqSorted.end()) << std::endl;
    std::cout << "Time to process a range of " << deqSTL.size() <<" elements with std::deqSTL " << elapsed(deqSTLBegin, deqSTLEnd) << "us" << std::endl;

    std::cout << "=======LST==========" << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << elapsed(listBegin, listEnd) << "us" <<std::endl;
    std::cout << "Is list sorted : " <<  std::is_sorted(lstSorted.begin(), lstSorted.end()) << std::endl;
    std::cout << "Time to process a range of " << lstSTL.size() <<" elements with std::lstSTL " << elapsed(lstSTLBegin, lstSTLEnd) << "us" << std::endl;
    
    std::cout << "=======VEC==========" << std::endl;
    std::cout << "Time to process a range of " << vec.size() <<" elements with std::vec: " << elapsed(vecBegin, vecEnd) << "us" << std::endl;
    std::cout << "Is list sorted : " <<  std::is_sorted(vecSorted.begin(), vecSorted.end()) << std::endl;
    std::cout << "Time to process a range of " << vecSTL.size() <<" elements with std::vecSTL " << elapsed(vecSTLBegin, vecSTLEnd) << "us" << std::endl;

    return (0);
}
