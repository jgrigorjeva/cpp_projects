#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

Form::Form(): _name("default_name"), _is_signed(false), _grade_to_sign(1), _grade_to_exe(1) {}

Form::Form(std::string name, int grade_to_sign, int grade_to_exe): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exe(grade_to_exe)
{
    if (grade_to_sign < TOPGRADE || grade_to_exe < TOPGRADE)
        throw GradeTooHighException();
    if (grade_to_sign > BOTTOMGRADE || grade_to_exe > BOTTOMGRADE)
        throw GradeTooLowException();
}

Form::Form(const Form & other): _name(other._name), _is_signed(other._is_signed), _grade_to_sign(other._grade_to_sign), _grade_to_exe(other._grade_to_exe)
{
    // hypothetically
    if (_grade_to_sign < TOPGRADE || _grade_to_exe < TOPGRADE)
        throw GradeTooHighException();
    if (_grade_to_sign > BOTTOMGRADE || _grade_to_exe > BOTTOMGRADE)
        throw GradeTooLowException();
}
Form & Form::operator=(const Form & other)
{
    (void)other;
    return *this;
}

Form::~Form() {}

// members
void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= _grade_to_sign)
        _is_signed = true;
    else
        throw GradeTooLowException();    
}


// exceptions
const char* Form::GradeTooHighException::what() const throw()
{
    return (BR "Form: Grade is too high!" RST);
}

const char* Form::GradeTooLowException::what() const throw()
{
    return (BR "Form : Grade is too low!" RST);
}

// getters
std::string Form::getName() const
{
    return _name;
}

bool Form::getSignedStatus() const
{
    return _is_signed;
}

int  Form::getGradeToSign() const
{
    return _grade_to_sign;
}

int  Form::getGradeToExe() const
{
    return _grade_to_exe;
}

// insertion overload
std::ostream& operator<<(std::ostream& out, const Form& src)
{
   return out << BG << src.getName() << RST<< ", grade to sign " 
   << BB << src.getGradeToSign() << RST<< ", grade to execute " 
   << BB << src.getGradeToExe() << RST << ", is signed " 
   << BB << src.getSignedStatus() << RST <<".\n";
}