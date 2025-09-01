#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }
    Harl Caren;
   	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for (; i < 4; i++)
	{
		if (levels[i] == argv[1])
			break;
	}
	switch (i)
	{
		case (0):
			Caren.complain(levels[0]);
		case (1):
			Caren.complain(levels[1]);
		case (2):
			Caren.complain(levels[2]);
		case (3):
			Caren.complain(levels[3]);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}   
}