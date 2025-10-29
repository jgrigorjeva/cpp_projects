#ifndef GROUND
#define GROUND

#include "AMateria.hpp"

class Ground
{
    private:
    int _item_count;
    int _capacity;

    void _resize(int newCapacity);

    public:
    Ground();
    Ground(const Ground &other);
    ~Ground();
    Ground &operator=(const Ground &other);
    AMateria **items;
    int get_count();
    void storeMateria(AMateria* m);
    void cleanup();
    
};

#endif