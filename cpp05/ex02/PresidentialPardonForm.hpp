#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
    private:
    std::string _target;
    void _doPardon() const;

    public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &);
    PresidentialPardonForm(const PresidentialPardonForm &);
    ~PresidentialPardonForm();
    AForm & operator=(const PresidentialPardonForm &);
    // members
    void doExecute() const;    
};

#endif