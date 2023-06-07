#include "../Includes/MergeInsert.hpp"
#include <algorithm>
#include <sstream>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
//check for duplicates at the begining??
//-> exclude parsing and array from actual sorting
int main(int ac, char **av) {
    (void) ac;
    std::vector<int> vec;
    std::deque<int> deq;
    for (unsigned int i = 1; av[i]; i++){
        std::stringstream ss(av[i]);
        int val;

        ss >> val;
        if (ss.fail()) {
            std::cerr << "Error while parsing input" << std::endl;
            return (1);
        }
        vec.push_back(val);
        deq.push_back(val);
    }
    mergeInsert(vec);
    //mergeInsert(deq);
    return (0);

}
