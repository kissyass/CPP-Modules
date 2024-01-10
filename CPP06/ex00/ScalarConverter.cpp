#include "./ScalarConverter.hpp"

char ScalarConverter::c = 0;
int ScalarConverter::i = 0;
double ScalarConverter::d = 0.0;

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

void ScalarConverter :: updateAndPrint(void)
{
    if (i < 32 || i > 126)
        std::cout << "char: non displayable" << std::endl;
    else
    {
        c = static_cast<char>(i);
        std::cout << "char: " << c << std::endl;
    }

    d = static_cast<double>(i);
    
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << d << "f" << std::endl; //to print float numbers with fixed number after .
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
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

int ScalarConverter :: checkDouble(std::string str)
{
    d = std::stod(str);

    i = static_cast<int>(d);

    std::cout << "char: non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << d << "f" << std::endl; //to print float numbers with fixed number after .
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    return 1;
}

int ScalarConverter :: checkNum(std::string str)
{
    long int a;
    unsigned int j;
    int zero;

    j = 0;
    zero = 0;
    if (str[j] == '-' || str[j] == '+')
        j++;
    while (str[j] && isdigit(str[j]))
        j++;
    if (j != str.length() && str[j] != '.')
        throw InvalidInputException();

    if (str[j] == '.')
        j++;
    while (str[j] && isdigit(str[j]))
    {
        if (str[j] != '0')
            zero = 1;
        j++;
    }
    if (j != str.length() && !(str[j] == 'f' && j + 1 == str.length()))
        throw InvalidInputException();
    
    a = atol(str.c_str()); // Convert the std::string to a C-style string using c_str()
    if (a > INT_MAX || a < INT_MIN)
    {
        printVals("impossible", "impossible", "beyond conversion", "beyond conversion");
        return 1;
    }

    if (str.find('.') != std::string::npos && zero == 1)
        checkDouble(str);
    else
    {
        i = a;
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
    if (checkNum(str))
        return ;
}

const char * ScalarConverter::InvalidInputException::what() const throw()
{
    return ("Invalid input");
}