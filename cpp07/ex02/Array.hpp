#ifndef ARRAYHPP
#define ARRAYHPP

#include <exception>
#include <cstdlib>

template <typename T>
class  Array
{
    private:
    T* _array;
    unsigned int _size;

    public:
    Array(): _array(NULL), _size(0){};
    Array(unsigned int n): _size(n)
    {
        if (n == 0)
            _array = NULL;
        else
            _array = new T[n];
            // _array = new T[n]();
    }
    Array(const Array& other): _size(other._size)
    {
        if (_size == 0)
            _array = NULL;
        else
        {
            _array = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
    }

    ~Array()
    { 
        if (_array)
            delete[] _array; 
    };

    // overloads
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _array;
            _size = other._size;
            if (_size == 0)
                _array = NULL;
            else
            {
                _array = new T[_size]();
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = other._array[i];
            }
        }
        return *this;
    }

    T operator[](unsigned int i)
    {
        if (i >= _size || _array ==  NULL)
            throw OutOfBoundsException();
        return _array[i];
    }

    //  Exceptions
    class OutOfBoundsException : public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return ("Index out of bounds");
        }
    };

    // members
    unsigned int size() const
    {
        return _size;
    }

    void setElement(unsigned int i, T element)
    {
        if (!_array || i >= _size)
            return;
        _array[i] = element;
    }


};



#endif