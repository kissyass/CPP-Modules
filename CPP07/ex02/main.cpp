#include "Array.hpp"

int main()
{
    Array<int> arr;
    Array<int> a(10);

    std::cout << "First array size: " << arr.size() << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i;
    std::cout << "Second array size: " << arr.size() << std::endl;
    std::cout << "Second array size arguments: " << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;
    return 0;
}