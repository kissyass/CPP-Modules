#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip> // for std::fixed ; std::setprecision(1)
#include <cstdlib>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &rhs);
        ~ScalarConverter(void);

        static char c;
        static int i;
        static double d;

        static int checkNan(std::string str);
        static void printVals(std::string cs, std::string is, std::string fs, std::string ds);
        static int checkCharDigit(std::string str);
        static void updateAndPrint(void);
        static int checkNum(std::string);
        static int checkDouble(std::string str);  
    public:
        static void convert(std::string str);
        class InvalidInputException;
};

class ScalarConverter :: InvalidInputException : public std::exception
{
    public:
        virtual const char *what() const throw();
};

#endif