#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
    private:
    std::string _target;
    void _doRobotomy() const;

    public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &);
    RobotomyRequestForm(const RobotomyRequestForm &);
    ~RobotomyRequestForm();
    AForm & operator=(const RobotomyRequestForm &);
    // members
    void doExecute() const;    
};

#endif