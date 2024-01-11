#include "Array.hpp"

int main()
{
    Array<int> arr;

    std::cout << "First array size: " << arr.size() << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    try
    {
        Array<int> a(10);

        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i;
        std::cout << "Second array size: " << a.size() << std::endl;
        std::cout << "Second array size arguments: " << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << std::endl;
        std::cout << "Trying to access 10th index" << std::endl;
        std::cout << a[10];
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "-------------------------------------------------" << std::endl;
    Array<char> c(5);

    for (unsigned int i = 0; i < c.size(); i++)
        c[i] = i + 97;
    std::cout << "Char array size: " << c.size() << std::endl;
    std::cout << "Char array size arguments: " << std::endl;
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << c[i] << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    Array<std::string> s(5);

    for (unsigned int i = 0; i < c.size(); i++)
        s[i] = "Hello!";
    std::cout << "String array size: " << s.size() << std::endl;
    std::cout << "String array size arguments: " << std::endl;
    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << s[i] << std::endl;
    return 0;
}