#include <iostream>
#include <fstream>
#include <string>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Missing arguments"<< std::endl;
        return 1;
    }

    std::string data = "data.csv";
    BitcoinExchange database(data);

    
    std::ifstream input(argv[1], std::ios::in);
    std::string line;
    std::string date;
    float value;
    // std::time_t timestamp;
// 2011-01-03 | 3
    std::getline(input, line);
    while (std::getline(input, line))
    {
        try
        {
            size_t pipePos = line.find('|');
            if (pipePos == std::string::npos || pipePos == line.size() - 1)
                throw BadInputException();
            if (pipePos == 11)
            {
                date = line.substr(0, 10);
                // std::cout << "date: "  << date <<std::endl;
                // handle errors if rate is missing
                if (valIsMissing(line.substr(pipePos + 2)))
                    throw BadInputException();
                value = std::atof(line.substr(pipePos + 2).c_str());
                if (value < 0)
                    throw NegativeValueException();
                else if (value > 1000)
                    throw TooLargeValueException();
                float rate = database.getExchangeRate(date);
                std::cout << date << " => " << value << " * " << rate << " = " << value * rate << std::endl;

            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " => " << date << '\n';
        }
        
        
    }

    // try
    // {
    //     database.getExchangeRate("2022-03-25");
    //     database.getExchangeRate("2022-03-26");
    //     // database.getExchangeRate("2009-01-01");
    //     database.getExchangeRate("2009-02-29");
    // }
    // catch(const std::exception& e)
    // {
    //     // may add a line directing to the corresponding date in the sheet
    //     std::cerr << e.what() << '\n';
    // }
    
    
    (void)database;
    (void)argv;
    (void)value;
}