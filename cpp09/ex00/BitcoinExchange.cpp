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
    std::time_t timestamp;

    std::getline(file, line);
    while (std::getline(file, line))
    {
        try
        {
            size_t commaPos = line.find(',');
            if (commaPos != std::string::npos)
            {
                date = line.substr(0, commaPos);
                // std::cout << "date: "  << date <<std::endl;
                // handle errors if rate is missing
                rate = std::atof(line.substr(commaPos + 1).c_str());
                timestamp = stringToTimestamp(date);
                database.insert(std::make_pair(timestamp, rate));
                // std::cout << "date: "  << date << ", rate: " << rate << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
    }
}
BitcoinExchange::BitcoinExchange(BitcoinExchange& other)
{
    database = other.database;
}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& other)
{
    if (this != &other)
    {
        database = other.database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

int BitcoinExchange::getExchangeRate(std::string dateStr)
{
    time_t otherTm = stringToTimestamp(dateStr);
    std::map<std::time_t, float>::iterator it = database.lower_bound(otherTm);
    if (it == database.end())
    {
        --it;
    }
    else if (it->first != otherTm)
    {
        if (it != database.begin())
            --it;
        else
            throw NoEarlierDateException();
    }
        
    
    // std::cout << "for date: " << dateStr << ", this rate was found: " << it->second << std::endl;
    return it->second;    
}


std::time_t stringToTimestamp(std::string& line)
{

    struct tm date;
    time_t timestamp;

    if (line.size() != 10)
    {
        throw IncorrectDateException();
    }
    // std::cout << "string date: " << line << std::endl;
    date.tm_year = std::atoi(line.substr(0,4).c_str()) - 1900;
    date.tm_mon = std::atoi(line.substr(5, 2).c_str()) - 1;
    date.tm_mday = std::atoi(line.substr(8).c_str());
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;
    // date.tm_isdst = 0; // Not daylight saving
    if (date.tm_mon < 0 || date.tm_mon > 12 || date.tm_mday < 0 || date.tm_mday > 31)
        throw IncorrectDateException();
    // std::cout << std::asctime(&date);
    
    timestamp = mktime(&date);
    // std::cout << "timestamp: " << timestamp << std::endl;
    return timestamp;
}

// exceptions
const char* IncorrectDateException::what() const throw()
{
    return ("Incorrect date format");
}

const char* NegativeValueException::what() const throw()
{
    return ("Error: not a positive number.");
}
const char* TooLargeValueException::what() const throw()
{
    return ("Error: too large a number.");
}

const char* BitcoinExchange::NoEarlierDateException::what() const throw()
{
    return ("No previous database entry exists for this date");
}