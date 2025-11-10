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
    Bureaucrat jane2(plain_jane);
    Bureaucrat jane3;
    jane3   = plain_jane;
    std::cout << bob;
    std::cout << poor_pete;
    std::cout <<plain_jane;
    std::cout << BOLD "*** these are a copy and a \"=\" of Jane ***" RST << std::endl;
    std::cout <<jane2;
    std::cout << jane3;

    std::cout << BOLD "\n*** create valid Forms ***" RST << std::endl;
    Form default_form;
    std::cout << default_form;
    Form high_form("Highest form", 1, 1);
    std::cout << high_form;
    Form low_form("Lowest form", 150, 150);
    std::cout << low_form;
    std::cout << BOLD "*** Sign a form (to test copy constructors) ***" RST << std::endl;
    poor_pete.signForm(low_form);
    std::cout << low_form;

    std::cout << BOLD "*** these are a copy and a \"=\" of Lowest form ***" RST << std::endl;
    Form lowest_copy(low_form);
    std::cout << lowest_copy;
    Form lowest_copy2;
    lowest_copy2 = low_form;
    std::cout << lowest_copy2;

    std::cout << BOLD "\n*** Check exceptions in the form construction ***" RST << std::endl;
    try
    {
        Form invalid_form("invalid form", -10, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form invalid_form("invalid form", 1, 155);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << BOLD "\n*** Check invalid sign requests ***" RST << std::endl;
    jane2.signForm(high_form);
    

    
}