#include "RPN.hpp"

RPN :: RPN()
{}

RPN :: RPN(const RPN & copy)
{
    *this = copy;
}

RPN & RPN :: operator=(const RPN &rhs)
{
    this->st = rhs.st;

    return *this;
}

RPN :: ~RPN()
{
    while (this->st.size() > 0)
        st.pop();
}

void RPN :: readInput(std::string str)
{
    std::string ops = "+-/*";

    for (size_t i = 0; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
            this->st.push(str[i] - 48);
        else if (std::isspace(str[i]))
            ;
        else if (ops.find(str[i]) != std::string::npos)
        {
            if (!makeOperation(str[i]))
            {
                std::cerr << "Error" << std::endl;
                return ;
            }
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }

    if (this->st.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return ;
    }

    std::cout << this->st.top() << std::endl;
    this->st.pop();
}

bool RPN :: makeOperation(char c)
{
    if (this->st.size() < 2)
        return false;
    
    int number = 0;

    switch (c)
    {
        case '+':
            number = this->st.top();
            this->st.pop();
            number = this->st.top() + number;
            this->st.pop();
            this->st.push(number);
            break;
        case '-':
            number = this->st.top();
            this->st.pop();
            number = this->st.top() - number;
            this->st.pop();
            this->st.push(number);
            break;
        case '/':
            number = this->st.top();
            this->st.pop();
            number = this->st.top() / number;
            this->st.pop();
            this->st.push(number);
            break;
        case '*':
            number = this->st.top();
            this->st.pop();
            number = this->st.top() * number;
            this->st.pop();
            this->st.push(number);
            break;
        default:
            return false;
    }

    return true;
}