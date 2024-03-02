#include "MutantStack.hpp"

int main()
{
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "MutantStack: " << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size : " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << "Iteration started: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "List:" << std::endl;

    std::list<int> mylist;

    mylist.push_back(5);
    mylist.push_back(17);

    std::cout << "Top: " << mylist.back() << std::endl;

    mylist.pop_back();

    std::cout << "Size : " << mylist.size() << std::endl;

    mylist.push_back(3);
    mylist.push_back(5);
    mylist.push_back(737);
    mylist.push_back(0);

    std::list<int>::iterator itl = mylist.begin();
    std::list<int>::iterator itel = mylist.end();

    ++itl;
    --itl;

    std::cout << "Iteration started: " << std::endl;
    while (itl != itel) 
    {
        std::cout << *itl << std::endl;
        ++itl;
    }

    return 0;
}
