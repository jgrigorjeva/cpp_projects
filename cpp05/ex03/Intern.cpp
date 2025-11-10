#include "Intern.hpp"
#include "Colors.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
    (void)other;
}
Intern::~Intern(){}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

// members
AForm* Intern::makeForm(std::string formName, std::string target)
{
    AForm *newForm;
    try
    {
        newForm = createForm(formName, target);
        std::cout << BB "Intern creates " << newForm->getName() << RST<< std::endl;
        return (newForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << BR "Form creation failed because " << e.what() <<  RST<< '\n';
    }
    return NULL;

}

AForm* Intern::createForm(std::string &formName, std::string &target)
{
    const std::string form_types[] = { "presidential pardon", "robotomy request", "shrubbery creation"};
    int i = 0;
    while (i < 3 && formName != form_types[i])
        i++;
    switch (i)
    {
    case 0:
       return new PresidentialPardonForm(target);
    case 1:
        return new RobotomyRequestForm(target);
    case 2:
        return new ShrubberyCreationForm(target);
    
    default:
        throw FormDoesNotExistException();
        break;
    }
    return NULL;
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
    return (BR "Requested form does not exist!" RST);
}