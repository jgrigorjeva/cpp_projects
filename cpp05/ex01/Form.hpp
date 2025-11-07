#ifndef FORM
#define FORM

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
    const std::string  _name;
    bool _is_signed;
    const int _grade_to_sign;
    const int _grade_to_exe;

    public:
    Form();
    Form(std::string name, int grade_to_sign, int grade_to_exe);
    Form(const Form &);
    Form & operator=(const Form &);
    ~Form();

    // members
    void beSigned(const Bureaucrat &b);

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
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif