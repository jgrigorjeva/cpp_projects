# Class templates

In this exercise, we are implementing a class template Array. 
Templates are instantiated at compile time when used, therefore, we need to have all function implementations visible at compile time.

This usually means: **Put all function implementations in the header** file, or in a **.tpp (or .inl)** file included at the end of the header.

## The constructors

The default constructor creates an empty array (which in our case means array = NULL).
Therefore, the values in the constructor are initialized as follows:
```
Array(): _array(NULL), _size(0){};
```

The parametrized constructor takes the array size (unsigned int), memory is allocated:
```
Array(unsigned int n): _size(n)
{
    if (n == 0)
        _array = NULL;
    else
        _array = new T[n]();
}
```
The element values should be initialized, hence the **()** in **T[n]()**. The () indicate that if T is a builtin type, its value is set to 0 (for int), 0.0 (for float), NULL (for a pointer), etc. If T was a custom type, we could do without the (), since T[n] calls a default constructor for that class -> the T is defined by the constructor. If builtin elements were created without initialization, their values would be random.