#ifndef GROUND
#define GROUND

#include "AMateria.hpp"

class Ground
{
    private:
    AMateria **_items;
    int _item_count;
    int _capacity;

    void _resize(int newCapacity);

    public:
    Ground();
    Ground(const Ground &other);
    ~Ground();
    Ground &operator=(const Ground &other);
    
    void storeMateria(AMateria* m);
    void cleanup();
    
};

#endif