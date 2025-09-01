#include "Harl.hpp"

int main()
{
    Harl Caren;
   	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int complains_nbr = 10;

    for (int i = 0; i < complains_nbr; i++)
    {
        std::cout << "*** Complain number " << i+1 << " ***" << std::endl;
        Caren.complain(levels[i % 4]);
    }    
}