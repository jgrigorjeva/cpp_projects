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

};

std::time_t stringToTimestamp(std::string);

#endif