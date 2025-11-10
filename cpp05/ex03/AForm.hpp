#ifndef AFORM
#define AFORM

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
    const std::string  _name;
    bool _is_signed;
    const int _grade_to_sign;
    const int _grade_to_exe;

    public:
    AForm();
    AForm(std::string name, int grade_to_sign, int grade_to_exe);
    AForm(const AForm &);
    AForm & operator=(const AForm &);
    virtual ~AForm();

    // members
    void execute(Bureaucrat const & executor) const;
    void beSigned(const Bureaucrat &b);
    virtual void doExecute() const = 0;

    // getters
    std::string getName() const;
    bool getSignedStatus() const;
    int  getGradeToSign() const;
    int  getGradeToExe() const;

    // exceptions
    class GradeTooHighException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
    class FormIsUnsignedException : public std::exception 
    {
        public:
        const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& out, const AForm& src);

#endif