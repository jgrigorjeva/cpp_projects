#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <map>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include  <cstring>


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

    float getExchangeRate(std::string);
    class NoEarlierDateException : public std::exception 
    {
        public:
        const char*		what() const throw();
    };

};

std::time_t stringToTimestamp(std::string&);
bool valIsMissing(std::string dateStr);


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

class BadInputException : public std::exception 
{
    public:
    const char*		what() const throw();
};

#endif