#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// # include <string>
// # include <exception>
// # include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <set>

class EasyFindException : public std::exception {
	public:
		const char *what() const throw() {
			return "Element was not found in the container";
   		}
};

template<typename T>
void easyfind(T& container, int to_find)
{
	if (std::find(container.begin(), container.end(), to_find) == container.end())
		throw EasyFindException();
}

#endif