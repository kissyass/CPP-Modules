#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>

class RPN
{
    private:
        std::stack<int> st;
    public:
        RPN();
        RPN(const RPN & copy);
        RPN &operator=(const RPN &rhs);
        ~RPN();

        void readInput(std::string str);
        bool makeOperation(char c);

};

#endif