#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <list>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(void)
		{}

		MutantStack(const MutantStack &copy)
		{
			*this = copy;
		}

		MutantStack& operator=(const MutantStack &rhs)
		{
			if (this != &rhs)
				this->c = rhs.c;
			return *this;
		}

		~MutantStack(void) { }

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin() 
		{
			return this->c.begin();
		}
		iterator	end() 
		{
			return this->c.end();
		}
};

#endif