#include "./ScalarConverter.hpp"

char ScalarConverter :: c = 0;
int ScalarConverter :: i = 0;
float ScalarConverter :: f = 0;
double ScalarConverter :: d = 0;

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter & ScalarConverter :: operator=(const ScalarConverter &rhs)
{
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter(void)
{}

void ScalarConverter :: printVals(std::string cs, std::string is, std::string fs, std::string ds)
{
    std::cout << "char: " << cs <<std::endl;
    std::cout << "int: " << is <<std::endl;
    std::cout << "float: " << fs <<std::endl;
    std::cout << "double: " << ds <<std::endl;
}

int ScalarConverter :: checkNan(std::string str)
{
    std::string check[] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff", "inf", "inff"};
    int index;

    index = 0;
    while (index < 8 && str != check[index])
        index++;
    
    switch (index)
    {
    case 0:
        printVals("impossible", "impossible", "nanf", "nan");
        return 1;
    case 1:
        printVals("impossible", "impossible", "nanf", "nan");
        return 1;
    case 2:
        printVals("impossible", "impossible", "-inf", "-inff");
        return 1;
    case 3:
        printVals("impossible", "impossible", "-inf", "-inff");
        return 1;
    case 4:
        printVals("impossible", "impossible", "+inf", "+inff");
        return 1;
    case 5:
        printVals("impossible", "impossible", "+inf", "+inff");
        return 1;
    case 6:
        printVals("impossible", "impossible", "inf", "inff");
        return 1;
    case 7:
        printVals("impossible", "impossible", "inf", "inff");
        return 1;
    default:
        return 0;
    }
}

void updateAndPrint(void)
{
    c = static_cast<char>(i);
    f = static_cast<float>(i);
    d = static_cast<double>(i);
    
    std::cout << "char: " << c <<std::endl;
    std::cout << "int: " << i <<std::endl;
    std::cout << "float: " << f <<std::endl;
    std::cout << "double: " << d <<std::endl;
}

int ScalarConverter :: checkCharDigit(std::string str)
{
    if (str.length() > 1)
        return 0;

    if (isdigit(str[0]))
    {
        i = static_cast<int>(str[0] - '0');
        updateAndPrint();
    }
    else
    {
        i = static_cast<int>(str[0]);
        updateAndPrint();
    }
    return 1;
}

void ScalarConverter :: convert(std::string str)
{
    if (checkNan(str))
        return ;
    if (checkCharDigit(str))
        return ;
    
}