#include "PmergeMe.hpp"

PmergeMe :: PmergeMe()
{}

PmergeMe :: PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe & PmergeMe :: operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        this->lcont.clear();
        this->vcont.clear();
        this->lcont = rhs.lcont;
        this->vcont = rhs.vcont;
        this->listTime = rhs.listTime;
        this->vectorTime = rhs.vectorTime;
    }

    return *this;
}

PmergeMe :: ~PmergeMe()
{}

PmergeMe :: PmergeMe(int argc, char **input)
{
    for (int i = 1; i < argc; i++)
    {
        if (!checkInt(std::string(input[i])))
        {
            std::cout << "Error" << std::endl;
            return ;
        }
    }

    for (int i = 1; i < argc; i++)
    {
        if (!fillContainers(std::string(input[i])))
            return ;
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < this->vcont.size(); i++)
        std::cout << this->vcont[i] << " ";
    std::cout << std::endl;
    
    std::clock_t	clockBegin = clock();
    this->insertSortMergeVector(0, this->vcont.size(), 5);
    std::clock_t	clockEnd = clock();
    this->vectorTime = double(clockEnd - clockBegin) / CLOCKS_PER_SEC;

    clockBegin = clock();
    this->insertSortMergeList(this->lcont.begin(), this->lcont.end(), 5);
    clockEnd = clock();
    this->listTime = double(clockEnd - clockBegin) / CLOCKS_PER_SEC;

    std::cout << "After:";
    for (size_t i = 0; i < this->vcont.size(); i++)
        std::cout << this->vcont[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << argc - 1 << " elements with vector: " << std:: fixed << std::setprecision(6) << this->vectorTime << " us." << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with list: " << std:: fixed << std::setprecision(6) << this->listTime << " us." << std::endl;
}

bool PmergeMe :: checkInt(std::string str)
{
    for (size_t i = 0 ; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    return true;
}

bool PmergeMe :: fillContainers(std::string str)
{
    int num;

    try
    {
        num = std::stoi(str);
        this->lcont.push_back(num);
        this->vcont.push_back(num);
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        this->lcont.clear();
        this->vcont.clear();
        return false;
    }

    return true;
    
}


void PmergeMe :: insertSortMergeVector(int begin, int end, int threshold)
{
    if (end > begin && threshold > 0)
    {
        if (end - begin <= threshold) //a threshold value determines when to switch from using the merge sort algorithm to using the insertion sort algorithm for sorting smaller subarrays
            insertSortVector(begin, end);
        else
        {
            int mid = begin + (end - begin) / 2;
            this->insertSortMergeVector(begin, mid, threshold);
            this->insertSortMergeVector(mid, end, threshold);
            this->sortMergeVector(begin, mid, end);
        }
    }
    else
        std::cout << "Error: wrong index input" << std::endl;

}

void PmergeMe :: insertSortVector(int begin, int end)
{
    for (int i = begin + 1; i < end; i++)
    {
        int num = this->vcont[i];
        int j = i - 1;
        while (j >= begin && this->vcont[j] > num)
        {
            this->vcont[j + 1] = this->vcont[j];
            j--;
        }
        this->vcont[j + 1] = num;
    }
}

void PmergeMe :: sortMergeVector(int begin, int mid, int end)
{
    std::vector<int> v1, v2;

    for (int i = begin; i < mid; i++)
        v1.push_back(this->vcont[i]);
    for (int i = mid; i < end; i++)
        v2.push_back(this->vcont[i]);

    size_t i = 0, j = 0, k = begin;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
        {
            this->vcont[k] = v1[i];
            i++;
        }
        else
        {
            this->vcont[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < v1.size())
    {
        this->vcont[k] = v1[i];
        i++;
        k++;
    }

    while (j < v2.size())
    {
        this->vcont[k] = v2[j];
        j++;
        k++;
    }
}

void PmergeMe :: insertSortMergeList(std::list<int>::iterator begin, std::list<int>::iterator end, int threshold)
{
    if (std::distance(begin, end) > 0 && threshold > 0)
    {
        if (std::distance(begin, end) <= threshold)
            insertSortList(begin, end);
        else
        {
            std::list<int>::iterator mid = std::next(begin, std::distance(begin, end) / 2);
            insertSortMergeList(begin, mid, threshold);
            insertSortMergeList(mid, end, threshold);
            sortMergeList(begin, mid, end);
        }
    }
    else
        std::cout << "Error: wrong index input" << std::endl;
}

void PmergeMe :: insertSortList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
    for (std::list<int>::iterator it = std::next(begin); it != end; it++)
    {
        int num = *it;
        std::list<int>::iterator jt = it;
        while (jt != begin && *std::prev(jt) > num)
        {
            *jt = *std::prev(jt);
            jt--;
        }

        *jt = num;
    }
}

void PmergeMe :: sortMergeList(std::list<int>::iterator begin, std::list<int>::iterator mid, std::list<int>::iterator end)
{
    std::list<int> tmp;

    std::list<int>::iterator it1 = begin;
    std::list<int>::iterator it2 = mid;

    while (it1 != mid && it2 != end)
    {
        if (*it1 <= *it2)
        {
            tmp.push_back(*it1);
            it1++;
        }
        else
        {
            tmp.push_back(*it2);
            it2++;
        }
    }

    tmp.insert(tmp.end(), it1, mid);
    tmp.insert(tmp.end(), it2, end);

    std::copy(tmp.begin(), tmp.end(), begin);
}