#pragma once
#include <iostream>
#include <exception>
#include "Form.hpp"
#define TOPGRADE 1
#define BOTTOMGRADE 150

class Form;

class Bureaucrat
{
    private:
    const std::string _name;
    int         _grade;

    public:
    Bureaucrat();
    Bureaucrat(const std::string &, const int);
    Bureaucrat(const Bureaucrat &);
    Bureaucrat & operator=(const Bureaucrat &);
    ~Bureaucrat();
    // members
    std::string getName() const;
    int getGrade() const;
    void raiseGrade();
    void lowerGrade();
    void signForm(Form & form);
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

// operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);