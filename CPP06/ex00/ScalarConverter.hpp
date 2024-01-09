#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &rhs);
        ~ScalarConverter(void);

        static char c;
        static int i;
        static float f;
        static double d;

        static int checkNan(std::string str);
        void printVals(std::string cs, std::string is, std::string fs, std::string ds);
        int checkCharDigit(std::string str);
        void updateAndPrint(void);
        


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