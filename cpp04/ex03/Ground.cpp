#include "Ground.hpp"
#include "AMateria.hpp"

Ground::Ground(): _items(nullptr), _item_count(0), _capacity(4)
{
}

Ground::Ground(const Ground &other): _items(nullptr), _item_count(0), _capacity(4)
{
    if (other._item_count > 0)
    {
        _capacity = other._item_count;
        _items = new AMateria*[_capacity];
        for (int i = 0; i < other._item_count; i++)
            _items[i] = other._items[i];
        _item_count = other._item_count;
    }
}

Ground &Ground::operator=(const Ground &other)
{
    if (this != &other)
    {
        cleanup();
        delete[] _items;
        _items = nullptr;
        _capacity = 0;
        _item_count = 0;

        if (other._item_count > 0)
        {
            _capacity = other._item_count;
            _items = new AMateria*[_capacity];
            for (int i = 0; i < other._item_count; i++)
                _items[i] = other._items[i];
            _item_count = other._item_count;
        }
    }
    return *this;
}

Ground::~Ground()
{
    cleanup();
    delete[] _items;
}

void Ground::cleanup()
{
    for (int i=0; i < _item_count; i++)
    {
        delete _items[i];
        _items[i] = nullptr;
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
    _items[_item_count++] = m;
    std::cout << "[Ground] Stored " << m->getType()
              << " materia (total: " << _item_count << ")\n";
}

void Ground::_resize(int newCapacity)
{
    AMateria **newArray = new AMateria*[newCapacity];
    for (int i = 0; i < _item_count; i++)
        newArray[i] = _items[i];
    delete[] _items;
    _items = newArray;
    _capacity = newCapacity;
}