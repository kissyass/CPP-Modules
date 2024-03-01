#include "Span.hpp"

int main ()
{
    Span sp = Span(5);
    sp.addNumber(6);
    
    try 
    {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    } 
    catch (const std::exception &ex) 
    {
        std::cerr << "Exception cought: " << ex.what() << std::endl;
    }
    
    try 
    {
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } 
    catch (const std::exception &ex) 
    {
        std::cerr << "Exception cought: " << ex.what() << std::endl;
    }

    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    try 
    {
        int arr[] = { 1, 2, 3, 4, 5 };
        int n = sizeof(arr) / sizeof(arr[0]);
        std::vector<int> vec(arr, arr + n);
        sp.addNumbers(vec.begin(), vec.end());
    } 
    catch (const std::exception &ex) 
    {
        std::cerr << "Exception cought: " << ex.what() << std::endl;
    }

    try 
    {
        sp.addNumber(33);
    } 
    catch (const std::exception &ex) 
    {
        std::cerr << "Exception cought: " << ex.what() << std::endl;
    }

    sp.print_span();
    return 0;
}