#include "Ground.hpp"
#include "AMateria.hpp"

Ground::Ground(): _item_count(0), _capacity(4), items(NULL)
{
    items = new AMateria*[_capacity];
}

Ground::Ground(const Ground &other): _item_count(0), _capacity(4), items(NULL)
{
    if (other._item_count > 0)
    {
        _capacity = other._item_count;
        items = new AMateria*[_capacity];
        for (int i = 0; i < other._item_count; i++)
            items[i] = other.items[i];
        _item_count = other._item_count;
    }
}

Ground &Ground::operator=(const Ground &other)
{
    if (this != &other)
    {
        cleanup();
        delete[] items;
        items = NULL;
        _capacity = 0;
        _item_count = 0;

        if (other._item_count > 0)
        {
            _capacity = other._item_count;
            items = new AMateria*[_capacity];
            for (int i = 0; i < other._item_count; i++)
                items[i] = other.items[i];
            _item_count = other._item_count;
        }
    }
    return *this;
}

Ground::~Ground()
{
    cleanup();
    delete[] items;
}

void Ground::cleanup()
{
    for (int i=0; i < _item_count; i++)
    {
        delete items[i];
        items[i] = NULL;
    }
    _item_count = 0;
}

void Ground::storeMateria(AMateria* m)
{

    if (!m)
        return ;
    if (_item_count >= _capacity)
    {
        int newCapacity = _capacity * 2;
        _resize(newCapacity);
    }
    items[_item_count++] = m;
    std::cout << "[Ground] Stored " << m->getType()
              << " materia (total: " << _item_count << ")\n";
}

void Ground::_resize(int newCapacity)
{
    AMateria **newArray = new AMateria*[newCapacity];
    for (int i = 0; i < _item_count; i++)
        newArray[i] = items[i];
    delete[] items;
    items = newArray;
    _capacity = newCapacity;
}

int Ground::get_count()
{
    return (_item_count);
}