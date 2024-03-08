#include "BitcoinExchange.hpp"

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return (EXIT_FAILURE);
    }

    BitcoinExchange btc(argv[1]);

    return (EXIT_SUCCESS);
}