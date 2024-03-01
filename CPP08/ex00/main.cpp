#include "easyfind.hpp"

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int find_val = 3;
    int not_find = 7;

    // Example 1: Using easyfind with a vector
    std::vector<int> vec(arr, arr + n);
    try {
        easyfind(vec, find_val);
        std::cout << "Value " << find_val << " is found in the list." << std::endl;
        easyfind(vec, not_find);
        std::cout << "Value " << not_find << " is not found in the list." << std::endl;
    } catch (const EasyFindException& e) {
        std::cerr << e.what() << std::endl;
    }

    // Example 2: Using easyfind with a list
    std::list<int> lst(arr, arr + n);
    try {
        easyfind(lst, find_val);
        std::cout << "Value " << find_val << " is found in the list." << std::endl;
        easyfind(lst, not_find);
        std::cout << "Value " << not_find << " is not found in the list." << std::endl;
    } catch (const EasyFindException& e) {
        std::cerr << e.what() << std::endl;
    }

    // Example 3: Using easyfind with a set
    std::set<int> st(arr, arr + n);
    try {
        easyfind(st, find_val);
        std::cout << "Value " << find_val << " is found in the list." << std::endl;
        easyfind(st, not_find);
        std::cout << "Value " << not_find << " is not found in the list." << std::endl;
    } catch (const EasyFindException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
