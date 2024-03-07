#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

class PmergeMe{
    private:
        int listTime;
        int vectorTime;
        std::list<int> lcont;
        std::vector<int> vcont;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &rhs);
        ~PmergeMe();

        PmergeMe(int argc, char **input);
        bool checkInt(std::string str);
        bool fillContainers(std::string str);
        void insertSort();
        void sortMerge();
};

#endif