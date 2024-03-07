#include "PmergeMe.hpp"

// PmergeMe :: PmergeMe();
// PmergeMe :: PmergeMe(const PmergeMe &copy);
// PmergeMe & PmergeMe :: operator=(const PmergeMe &rhs);
// PmergeMe :: ~PmergeMe();

PmergeMe :: PmergeMe(int argc, char **input)
{
    for (size_t i = 1; i < argc; i++)
    {
        if (!checkInt(std::string(input[i])))
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }

    for (size_t i = 1; i < argc; i++)
    {
        if (!fillContainers(std::string(input[i])))
            return ;
    }
    


}

bool PmergeMe :: checkInt(std::string str)
{
    for (size_t i = 0 ; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
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
        std::cerr << "Error: " << e.what() << std::endl;
        this->lcont.clear();
        this->vcont.clear();
        return false;
    }

    return true;
    
}

void PmergeMe :: insertSort()
{

}


// void PmergeMe :: sortMerge();