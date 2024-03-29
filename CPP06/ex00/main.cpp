#include "./ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 0;
    }
    
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (const ScalarConverter::InvalidInputException & e)
    {
        std::cout << e.what() << std::endl;
    }
    
}