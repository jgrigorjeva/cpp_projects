#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

AForm::AForm(): _name("default_name"), _is_signed(false), _grade_to_sign(1), _grade_to_exe(1) 
{
    //  std::cout << "AForm default constructor\n";
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exe): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exe(grade_to_exe)
{
    // std::cout << "AForm parametrized constructor\n";
    if (grade_to_sign < TOPGRADE || grade_to_exe < TOPGRADE)
        throw GradeTooHighException();
    if (grade_to_sign > BOTTOMGRADE || grade_to_exe > BOTTOMGRADE)
        throw GradeTooLowException();
}

AForm::AForm(const AForm & other): _name(other._name), _is_signed(false), _grade_to_sign(other._grade_to_sign), _grade_to_exe(other._grade_to_exe)
{
    // std::cout << "AForm copy constructor\n";
    // hypothetically
    if (_grade_to_sign < TOPGRADE || _grade_to_exe < TOPGRADE)
        throw GradeTooHighException();
    if (_grade_to_sign > BOTTOMGRADE || _grade_to_exe > BOTTOMGRADE)
        throw GradeTooLowException();
}
AForm & AForm::operator=(const AForm & other)
{
    // std::cout << "AForm copy assignment operator\n";
    (void)other;
    return *this;
}

AForm::~AForm() {}

// members
void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= _grade_to_sign)
        _is_signed = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!getSignedStatus())
        throw FormIsUnsignedException();
    else if (executor.getGrade() > _grade_to_exe)
        throw GradeTooLowException();
    doExecute();
}



// exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
    return (BR "Grade is too high!" RST);
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return (BR "Grade is too low!" RST);
}

const char* AForm::FormIsUnsignedException::what() const throw()
{
    return (BR "Form is unsigned!" RST);
}


// getters
std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSignedStatus() const
{
    return _is_signed;
}

int  AForm::getGradeToSign() const
{
    return _grade_to_sign;
}

int  AForm::getGradeToExe() const
{
    return _grade_to_exe;
}

// insertion overload
std::ostream& operator<<(std::ostream& out, const AForm& src)
{
   return out << BG << src.getName() << RST<< ", grade to sign " 
   << BB << src.getGradeToSign() << RST<< ", grade to execute " 
   << BB << src.getGradeToExe() << RST << ", is signed " 
   << BB << src.getSignedStatus() << RST <<".\n";
}