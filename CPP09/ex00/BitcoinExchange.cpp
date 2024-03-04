#include "BitcoinExchange.hpp"

BitcoinExchange :: BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        
}

std::map<std::string, float> readCSVToMap(const std::string& filename) {
    std::map<std::string, float> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return data;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string dateStr;
        float rate;
        char delimiter;
        if (std::getline(ss, dateStr, ',') && ss >> rate && ss >> delimiter) {
            data[dateStr] = rate;
        }
    }
    
    file.close();
    return data;
}
