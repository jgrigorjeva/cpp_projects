#include "Base.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base(){}

Base * generate(void)
{
    
    int random = std::rand() % 3;
    switch (random)
    {
    case 0:
        std::cout <<BG "Class A generated\n" RST;
        return new A;
        
    case 1:
        std::cout << BG "Class B generated\n" RST;
        return new B;
    case 2:
        std::cout << BG "Class C generated\n" RST;
        return new C;
    
    default:
        return NULL;
    }
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A identified from pointer\n";
    if (dynamic_cast<B*>(p))
        std::cout << "Class B identified from pointer\n";
    if (dynamic_cast<C*>(p))
        std::cout << "Class C identified from pointer\n";

}
void identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "Class A identified from reference\n";
    if (dynamic_cast<B*>(&p))
        std::cout << "Class B identified from reference\n";
    if (dynamic_cast<C*>(&p))
        std::cout << "Class C identified from reference\n";
}