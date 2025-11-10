#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery form", 145, 137), _target("default_target")
{
    // std::cout << BG "Shrubbery form default constructor" RST << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery form", 145, 137), _target(target)
{
    // std::cout << BG "Shrubbery form parametrized constructor" RST << std::endl;

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm("Shrubbery form", 145, 137), _target(other._target)
{
    // std::cout << BG "Shrubbery form copy constructor" RST << std::endl;
    (void)other;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

AForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    // std::cout << BG "Shrubbery form copy assignment operator" RST << std::endl;
    (void)other;
    return *this;
}

void ShrubberyCreationForm::_makeShrub() const
{
    std::string treeCMD = "tree --charset=ASCII  > ";
    std::string cmd = treeCMD + _target + "_shrubbery";
    std::system(cmd.c_str());
}

void ShrubberyCreationForm::doExecute() const
{
    _makeShrub();
}