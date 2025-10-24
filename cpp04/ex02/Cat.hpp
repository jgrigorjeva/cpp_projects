#ifndef CAT
#define CAT

#include "AAnimal.hpp"
#include "Colors.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    // in c++11, it is possible to inherit constructors like this:
    // Animal::Animal;
    private:
    Brain *_brain;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();
        // members
        void makeSound() const;
        void set_idea(int index, const std::string idea);
        std::string get_idea(int index) const;


};
#endif