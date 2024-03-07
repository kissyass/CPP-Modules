#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Not enough arguments" << std::endl;
        return (EXIT_FAILURE);
    }

    PmergeMe mr(argc, argv);
    return(EXIT_SUCCESS);
}