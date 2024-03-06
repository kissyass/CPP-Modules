#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange 
{
    private:
        std::map<int, float> data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

        BitcoinExchange(std::string fileName);

        int DateToInt(std::string str);
        bool checkYear(int year);
        bool checkMonth(int month);
        bool checkDay(int day, int date);
        float findRate(int date);
        void eraseSpace(std::string & str);

        class FileDoesNotOpenException;
};

class BitcoinExchange::FileDoesNotOpenException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif