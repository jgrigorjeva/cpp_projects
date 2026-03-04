#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): database()
{

}


BitcoinExchange::BitcoinExchange(const std::string& filename)
{
    std::ifstream file(filename.c_str(), std::ios::in);
    std::string line;
    std::string date;
    float rate;
    // std::time_t timestamp;

    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos)
        {
            date = line.substr(0, commaPos);
            // handle errors if rate is missing
            rate = std::atof(line.substr(commaPos + 1).c_str());
            // timestamp = stringToTimestamp(date);
            // database.insert(std::make_pair(timestamp, rate));
            // std::cout << "date: "  << date << ", rate: " << rate << std::endl;
        }
    }
}
//     BitcoinExchange(BitcoinExchange& other);
//     BitcoinExchange& operator=(BitcoinExchange& other);

BitcoinExchange::~BitcoinExchange(){}

// int getExchangeRate(std::string);