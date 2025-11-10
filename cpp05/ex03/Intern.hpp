#ifndef INTERN
#define INTERN

#include <iostream>
#include "AForm.hpp"

class Intern
{
    public:
    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern &operator=(const Intern &other);

    // members
    AForm* makeForm(std::string formName, std::string target);
    AForm* createForm(std::string &formName, std::string &target);
    class FormDoesNotExistException : public std::exception
    {
        public:
        const char *what() const throw();
    };

};

#endif