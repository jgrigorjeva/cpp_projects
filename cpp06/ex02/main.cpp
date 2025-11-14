#include "Base.hpp"
#include <ctime>
#include <cstdlib>



int main()
{
    Base* ptr;
    std::srand(std::time(0));
    for (int i = 0; i <10; i++){
        ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
    }
}