#include "Colors.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>
#include <exception>

int main()
{
    // std::cout << BOLD "*** create valid bureaucrats ***" RST << std::endl;
    // Bureaucrat bob("Bob", 1);
    // Bureaucrat poor_pete("Petr", 150);
    // Bureaucrat plain_jane("Jane", 80);
    // Bureaucrat jane2(plain_jane);
    // Bureaucrat jane3;
    // jane3   = plain_jane;
    // std::cout << bob;
    // std::cout << poor_pete;
    // std::cout <<plain_jane;
    // std::cout << BOLD "*** these are a copy and a \"=\" of Jane ***" RST << std::endl;
    // std::cout <<jane2;
    // std::cout << jane3;
    std::cout << BOLD "\n*** create an Intern ***" RST << std::endl;
    Intern intern;


    std::cout << BOLD "\n*** create valid Forms ***" RST << std::endl;
    AForm *shrub_default = intern.makeForm("shrubbery creation", "my_shrub");
    AForm *robo1 = intern.makeForm("robotomy request", "Bender");
    AForm *pardon1 = intern.makeForm("presidential pardon", "Ford Prefect");
    AForm *invalid = intern.makeForm("does not exist", "blabla");
    std::cout << *shrub_default;
    std::cout << *robo1;
    std::cout << *pardon1;

    // AForm *shrub1 = new ShrubberyCreationForm("folders");
    // AForm *shrub2 = new ShrubberyCreationForm();
    // *shrub1 = *shrub2;
    // AForm *shrub3 = new ShrubberyCreationForm(*dynamic_cast<ShrubberyCreationForm*>(shrub1));
    // AForm *robo2 = new RobotomyRequestForm(*dynamic_cast<RobotomyRequestForm*>(robo1));
    // AForm *pardon2 = new PresidentialPardonForm(*dynamic_cast<PresidentialPardonForm*>(pardon1));

    // std::cout << BOLD "\n*** Valid sign and execute Forms ***" RST << std::endl;
    // bob.signForm(*shrub1);
    // bob.executeForm(*shrub1);
    // bob.signForm(*robo1);
    // bob.executeForm(*robo1);
    // bob.executeForm(*robo1);
    // bob.executeForm(*robo1);
    // bob.executeForm(*robo1);
    // bob.signForm(*pardon1);
    // bob.executeForm(*pardon1);

    // std::cout << BOLD "\n*** Invalid sign abd execute attempts ***" RST << std::endl;
    // poor_pete.executeForm(*shrub2);
    // poor_pete.executeForm(*shrub1);
    // plain_jane.signForm(*robo1);
    // plain_jane.executeForm(*robo1);
    // plain_jane.executeForm(*robo2);
    // plain_jane.signForm(*pardon2);
    // plain_jane.executeForm(*pardon2);
 
    

    delete shrub_default;
    // delete shrub1;
    // delete shrub2;
    // delete shrub3;
    delete robo1;
    // delete robo2;
    delete pardon1;
    // delete pardon2;
    (void)invalid;

    
}