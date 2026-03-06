#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <map>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


class BitcoinExchange
{
    private:
    std::map<std::time_t, float> database;

    public:
    BitcoinExchange();
    BitcoinExchange(const std::string& filename);
    BitcoinExchange(BitcoinExchange& other);
    BitcoinExchange& operator=(BitcoinExchange& other);
    ~BitcoinExchange();

    int getExchangeRate(std::string);
    class NoEarlierDateException : public std::exception 
    {
        public:
        const char*		what() const throw();
    };

};

std::time_t stringToTimestamp(std::string&);
class IncorrectDateException : public std::exception 
{
    public:
    const char*		what() const throw();
};

class NegativeValueException : public std::exception 
{
    public:
    const char*		what() const throw();
};

class TooLargeValueException : public std::exception 
{
    public:
    const char*		what() const throw();
};

#endif