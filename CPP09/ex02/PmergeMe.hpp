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
        void insertSortMergeVector(int begin, int end, int threshold);
        void insertSortVector(int begin, int end);
        void sortMergeVector(int begin, int mid, int end);

        void insertSortMergeList(std::list<int>::iterator begin, std::list<int>::iterator end, int threshold);
        void insertSortList(std::list<int>::iterator begin, std::list<int>::iterator end);
        void sortMergeList(std::list<int>::iterator begin, std::list<int>::iterator mid, std::list<int>::iterator end);
};

#endif