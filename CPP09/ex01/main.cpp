#include "RPN.hpp"

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return (EXIT_FAILURE);
    }

    RPN rpn;
    rpn.readInput(argv[1]);

    return (EXIT_SUCCESS);
}