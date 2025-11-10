#include "RobotomyRequestForm.hpp"
#include "Colors.hpp"
#include <iostream>
// #include <fstream>
// #include <string>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy request form", 72, 45), _target("default_robot")
{
    // std::cout << BG "Robotomy request form default constructor" RST << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy request form", 72, 45), _target(target)
{
    // std::cout << BG "Robotomy request form parametrized constructor" RST << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm("Robotomy request form", 72, 45), _target(other._target)
{
    // std::cout << BG "Robotomy request form copy constructor" RST << std::endl;
    (void)other;
}
RobotomyRequestForm::~RobotomyRequestForm(){}

AForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    // std::cout << BG "Robotomy request form copy assignment operator" RST << std::endl;
    (void)other;
    return *this;
}

void RobotomyRequestForm::_doRobotomy() const
{
    std::cout << BOLD "Making drilling noises\n" RST;
    if (rand() % 2)
        std::cout << BOLD << _target << " was successfully robotomized\n" RST;
    else
        std::cout << BOLD << " Robotomy failed\n" RST;

}

void RobotomyRequestForm::doExecute() const
{
    _doRobotomy();
}