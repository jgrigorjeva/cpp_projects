#include <iostream>
#include <fstream>
#include <string>

#include "BitcoinExchange.hpp"

int main()
{
    std::string data = "data.csv";
    BitcoinExchange database(data);
    (void)database;
}