#include "Colors.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>

int main()
{
    std::cout << BOLD "*** create valid bureaucrats ***" RST << std::endl;
    Bureaucrat bob("Bob", 1);
    Bureaucrat poor_pete("Petr", 150);
    Bureaucrat plain_jane("Jane", 80);
    std::cout << bob;
    std::cout << poor_pete;
    std::cout <<plain_jane;

    std::cout << BOLD "*** create valid Forms ***" RST << std::endl;
    Form default_form;
    std::cout << default_form;
    Form high_form("For director", 1, 1);
    std::cout << high_form;
    
}