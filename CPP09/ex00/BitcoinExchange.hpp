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
        std::map<std::tm, std::float> data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy)
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

        class FileDoesNotOpenException;
}

class BitcoinExchange::FileDoesNotOpenException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif