# Passing function to a function template
In this exercise, we are supposed to create a function template (**iter**) that takes a pointer to an array (with unspecified element type), the length of the array, and a function that can be called on the array elements.
The function passed to the template can be instantiated from a function template, e.g.
```
template <typename T>
void printElement(const T& element)
{
    std::cout << element << std::endl;
}
```

In order to be able to pass the function to the **iter** template, we need to make it a function. Therefore, this call would not work:
```
int intArray[] = {1,2,3,4,5,6};
int *p = intArray;
iter(p, 6, printElement);
```
because the printElement is not a function yet. We need to specialize the type for printElement:
```
iter(p, 6, printElement<int>);
```
Now printElement<int> is an actual function.

## Support for const or non const arrays
We can make a template overload (define two **iter** templates that take const and mutable arrays):

```
template <typename T, typename Func>
void iter(T* array, const int len, Func f)
{
    for (int i = 0; i<len; i++)
    {
        f(array[i]);
    }
}

template <typename T, typename Func>
void iter(const T* array, const int len, Func f)
{
    for (int i = 0; i<len; i++)
    {
        f(array[i]);
    }
}
```