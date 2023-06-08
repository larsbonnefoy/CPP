#include "../Includes/MergeInsert.hpp"

const char *InvalidValueError::what(void) const throw() {
    return ("Invalid Value Input");
}

const char *DuplicateValueError::what(void) const throw() {
    return ("Duplicate Value in Input");
}

double elapsed(struct timeval	begin, struct timeval	end) {
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds*1e6 + microseconds;
	return (elapsed);
}

void parseInput(char **av, std::vector<int> &vec, std::list<int> &lst, std::deque<int> &deq) {
    for (unsigned int i = 1; av[i]; i++){
        std::stringstream ss(av[i]);
        int val;

        ss >> val;
        if (ss.fail() || val < 0) {
            throw InvalidValueError();
        }
        if (std::find(vec.begin(), vec.end(), val) != vec.end()) {
            throw DuplicateValueError();
        }
        vec.push_back(val);
        deq.push_back(val);
        lst.push_back(val);
    }
}
