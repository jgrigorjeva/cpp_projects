#ifndef SHRUBBERYCREATION
#define SHRUBBERYCREATION

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
    std::string _target;
    void _makeShrub() const;
    bool _shrubMade;

    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &);
    ShrubberyCreationForm(const ShrubberyCreationForm &);
    ~ShrubberyCreationForm();
    AForm & operator=(const ShrubberyCreationForm &);
    // members
    void doExecute() const;    
};

#endif