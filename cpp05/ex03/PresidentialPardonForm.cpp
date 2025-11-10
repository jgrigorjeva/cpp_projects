#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"
#include <iostream>
// #include <fstream>
// #include <string>
// #include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(): AForm("Pardon request form", 25, 5), _target("default_target")
{
    // std::cout << BG "Pardon request form default constructor" RST << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Pardon request form", 25, 5), _target(target)
{
    // std::cout << BG "Pardon request form parametrized constructor" RST << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm("Pardon request form", 25, 5), _target(other._target)
{
    // std::cout << BG "Pardon request form copy constructor" RST << std::endl;
    (void)other;
}
PresidentialPardonForm::~PresidentialPardonForm(){}

AForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    // std::cout << BG "Pardon request form copy assignment operator" RST << std::endl;
    (void)other;
    return *this;
}

void PresidentialPardonForm::_doPardon() const
{
    std::cout << BOLD << _target << " has been pardoned by Zaphod Beeblebrox.\n" RST;
}

void PresidentialPardonForm::doExecute() const
{
    _doPardon();
}