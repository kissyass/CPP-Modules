#include "BitcoinExchange.hpp"

BitcoinExchange :: BitcoinExchange()
{}

BitcoinExchange :: BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange & BitcoinExchange :: operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
        this->data = rhs.data;

    return (*this);
}

BitcoinExchange :: ~BitcoinExchange()
{}

BitcoinExchange :: BitcoinExchange(std::string fileName)
{
    if (!this->openCSV())
        return ;

    std::string line;
    std::ifstream fileInput(fileName);
    if (!fileInput.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return ;
    }

    std::getline(fileInput, line);
    
    while(std::getline(fileInput, line))
    {
        std::stringstream ss(line);
        std::string dateStr;
        float value;
        int date;

        size_t pos = line.find(" | ");
        dateStr = line.substr(0, pos);
        try
        {
            value = std::stof(line.substr(pos + 3));
            date = this->DateToInt(dateStr);
            if (date == 0)
                std::cout << "Error: bad input => " << dateStr << std::endl;
            else if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else if (value > 1000)
                std::cout << "Error: too large a number." << std::endl;
            else
                std::cout << dateStr << " => " << value << " = " << this->findRate(date) * value << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "Error: bad input => " << line.substr(pos + 3) << std::endl;
        }
    }

    fileInput.close(); 
}

bool BitcoinExchange :: openCSV()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string dateStr;
        float rate;

        if (std::getline(ss, dateStr, ',') && ss >> rate)
        {
            this->data[this->DateToInt(dateStr)] = rate;
        }
        else
        {
            std::cout << "Error: couldn't process file" << std::endl;
            return false;
        }
    }
    file.close();

    return true;
}


void BitcoinExchange :: eraseSpace(std::string & str)
{
    char spaceChar = ' ';
    
    size_t pos;
    while ((pos = str.find(spaceChar)) != std::string::npos) {
        str.erase(pos, 1);
    }
}

float BitcoinExchange :: findRate(int date)
{
    if (this->data.find(date) != this->data.end())
    {
        return this->data[date];
    }

    std::map<int, float>::iterator it = this->data.begin();
    while (it->first < date && it != this->data.end())
        it++;
    it--;
    return (it->second);
}

bool BitcoinExchange :: checkYear(int year)
{
    if (year >= 2009 && year <= 2022)
        return true;
    return false;
}

bool BitcoinExchange :: checkMonth(int month)
{
    if (month >= 1 && month <= 12)
        return true;
    return false;
}

bool BitcoinExchange :: checkDay(int day, int date)
{
    int month = date % 100;
    int year = date / 100;

    if ((month == 2 && year % 4 == 0) && (day >= 1 && day <= 29))
        return true;
    else if ((month == 2 && year % 4 != 0) && (day >= 1 && day <= 28))
        return true;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day >= 1 && day <= 30))
        return true;
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day >= 1 && day <= 31))
        return true;
    else
        return (false);
}

int BitcoinExchange :: DateToInt(std::string str)
{
    int date = 0;
    int check;

    if (str.size() != 10)
        return 0;

    size_t index = str.find('-');
    if (index != 4)
        return 0;

    index = str.find('-', index + 1);
    if (index != 7)
        return 0;

    check = std::atoi(str.substr(0, 4).c_str());
    if (this->checkYear(check) == false)
        return 0;
    date += check;

    check = std::atoi(str.substr(5, 2).c_str());
    if (this->checkMonth(check) == false)
        return 0;
    date = date * 100;
    date += check;

    check = std::atoi(str.substr(8, 2).c_str());
    if (this->checkDay(check, date) == false)
        return 0;
    date = date * 100;
    date += check;
    
    return (date);
}