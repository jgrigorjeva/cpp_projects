#ifndef BRAIN
#define BRAIN

#include <iostream>
#include "Colors.hpp"

class Brain
{
    private:
    std::string _ideas[100];

    public:
    Brain();
    Brain(std::string ideas[100]);
    Brain(const Brain& other);

    ~Brain();
    // setters
    void set_idea(int index, std::string idea);

    // getters
    std::string get_idea(int);

};

#endif