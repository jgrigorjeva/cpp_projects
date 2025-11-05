#include "Bureaucrat.hpp"
#include "Colors.hpp"

Bureaucrat::Bureaucrat(): _name("no_name"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string & name, const int grade): _name(name)
{
    if (grade < TOPGRADE)
        throw GradeTooHighException();
    if (grade > BOTTOMGRADE)
        throw GradeTooLowException();

    _grade = grade;
    
}
Bureaucrat::Bureaucrat(const Bureaucrat & other): _name(other._name)
{
    // purely hypothetically
    if (other._grade < TOPGRADE)
        throw GradeTooHighException();
    if (other._grade > BOTTOMGRADE)
        throw GradeTooLowException();
    _grade = other._grade;

}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

// members
std::string Bureaucrat::getName() const
{
    return _name;
}
int Bureaucrat::getGrade() const
{
    return _grade;
}
    
void Bureaucrat::raiseGrade()
{
    if (_grade <= TOPGRADE)
        throw GradeTooHighException();
    _grade--;
    std::cout << "Grade raised\n";
   
}
void Bureaucrat::lowerGrade()
{
    if (_grade >= BOTTOMGRADE)
        throw GradeTooLowException();
    _grade++;
    std::cout << "Grade lowered\n";
}

// exceptions
const char* Bureaucrat::GradeTooHighException::what()
{
    return (BR "Grade is too high!" RST);
}

const char* Bureaucrat::GradeTooLowException::what()
{
    return (BR "Grade is too low!" RST);
}

// operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& src)
{
   return out << BG << src.getName() << RST<< ", bureaucrat grade " << BB << src.getGrade() << RST<< ".\n";
}