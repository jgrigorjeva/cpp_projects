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

    std::cout << BOLD "\n*** create invalid bureaucrats ***" RST << std::endl;
    try 
    {
        Bureaucrat bob2("Bob", 0);
        Bureaucrat poor_pete2("Petr", 151);
    }
    catch (const std::exception& e) //Bureaucrat::GradeTooHighException inherits from std::exception
    {
        std::cerr << e.what() << '\n';
    }
    try 
    {
        Bureaucrat poor_pete2("Petr", 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << BOLD "\n*** Increment or decrement ***" RST << std::endl;
    std::cout << bob;
    try
    {
        bob.raiseGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    bob.lowerGrade();
    std::cout << bob << std::endl;

    std::cout << poor_pete;
    try
    {
        poor_pete.lowerGrade();
    }
    catch(Bureaucrat::GradeTooLowException& e) // just to demonstrate how the derived exception is caught
    {
        std::cerr << e.what() << '\n';
    }
    poor_pete.raiseGrade();
    std::cout << poor_pete << std::endl;
    
    std::cout << plain_jane;
    plain_jane.lowerGrade();
    std::cout << plain_jane;
    plain_jane.raiseGrade();
    std::cout << plain_jane << std::endl;

    std::cout << BOLD "\n*** Test some constructors ***" RST << std::endl;
    Bureaucrat default_bureaucrat;
    std::cout <<default_bureaucrat;
    // Bureaucrat copy_jane;
    // copy_jane = plain_jane; //the copy assignment operator does not work in the context of const attributes
    
}