# Containers
The standard library containers (std::vector, std::list, std::map, etc.) are implemented as class templates (see cpp07/ex02). Therefore, their code is generic, and the template parameter is the type of the stored elements, e. g.: `std::vector<int>` or `std::map<std::string, float>` - this is the template syntax. The compiler then generates a type-specific version of the container.

It works the same like in this example of a class template:
```
template <typename T>
class MyContainer {
    // template code using T
};
```
Then instantiate it:
```
MyContainer<int>    ints;
MyContainer<double> doubles;
```

Since templates work for any type (primitives, user-defined classes, pointers, etc.).

Templates also depend on allocators (also templates). An allocators is a policy object that defines how a container gets memory. You almost never need to specify the allocator yourself, there is a default allocator available.

## Vectors
Vectors (class Vector) are **dynamic arrays**. They can be declared with or without a given size, and then we can add elements to them. In the background, you create an array of a given size, when elements are added and if the updated array exceeds the memory allocated previously, new memory is allocated, the old elements are copied to it, new elements are added, and the old array is deleted (memory freed).

### template restrictions
We are supposed to create a function teplate that will work with containers. If container specific methods are used in the template, it will automatically restrict its types to container-like types. This is called **implicit constraints**. If you try to instantiate the function with a type that does not support the specific functions, it will produce a **compile error**.
### Iterators