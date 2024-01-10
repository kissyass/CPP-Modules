#include "iter.hpp"

template <typename T>
void print(T c)
{
    std::cout << c << std::endl;
}

template <typename T>
void cube(T &c)
{
    c = c + c + c;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "Printing array of integers with print function:" << std::endl;
    ::iter(arr, 7, print<int>);
    std::cout << "Printing array of integers with print function after cube function:" << std::endl;
    ::iter(arr, 7, cube<int>);
    ::iter(arr, 7, print<int>);

    char arr1[] = {'a', 'b', 'c', 'd'};
    std::cout << "Printing array of chars with print function:" << std::endl;
    ::iter(arr1, 4, print<char>);
    std::cout << "Printing array of chars with print function after cube function:" << std::endl;
    ::iter(arr1, 4, cube<char>);
    ::iter(arr1, 4, print<char>);

    std::string arr2[] = {"one", "two", "three"};
    std::cout << "Printing array of strings with print function:" << std::endl;
    ::iter(arr2, 3, print<std::string>);
    std::cout << "Printing array of strings with print function after cube function:" << std::endl;
    ::iter(arr2, 3, cube<std::string>);
    ::iter(arr2, 3, print<std::string>);

    return 0;
}