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

### template restrictions
We are supposed to create a function teplate that will work with containers. If container specific methods are used in the template, it will automatically restrict its types to container-like types. This is called **implicit constraints**. If you try to instantiate the function with a type that does not support the specific functions, it will produce a **compile error**.

### Iterators
An iterator points to a specific element of a specific container. In `c++98`, the type of the container has to be specified:
```
std::vector<int>::iterator i;
```
Since `c++14`, `auto` keyword can be used instead:
```
auto it = v.begin(); // the type of the iterator is deduced automatically
```
Where exactly does iterator point? This depends on the container type. E.g.:
`vector<T>::iterator`

- behaves like a raw pointer, dereferencing gives the element value
- you can do it + 5, random access

`list<T>::iterator`

- points to a node in a linked list
- can only move forward/backward (++it, --it)
- no random access

`map<K,V>::iterator`

- points to a tree node
- dereferencing gives a std::pair<const K, V>

# Sequence containers
## std::vector
Vectors (class Vector) are **dynamic arrays**. They can be declared with or without a given size, and then we can add elements to them. In the background, you create an array of a given size, when elements are added and if the updated array exceeds the memory allocated previously, new memory is allocated, the old elements are copied to it, new elements are added, and the old array is deleted (memory freed).
The c++98 version is old and clumsy and does not allow for this kind of initialization:
```
std::vector<int> v = {1, 2, 3};
```
You can declare the vector, and fill it by either using another int **array**:
```
int arr[] = {1, 2, 3};
std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
```
Or you can fill it using **push_back()** method:
```
std::vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
```
The vector also allows initialization using the fill constructor (fills the container elements with the same value)
```
std::vector<int> v(5, 42);   // 5 elements, all = 42
```

## std::inplace_vector
**since c++26**

## std::list
Lists are implemented like doubly linked lists. Therefore, it is easy to add elements to both sides (front and back). Inserting or erasing elements from inside positions is also possible. It lacks **direct** access to elements via index, but iterating is effective in both directions.
Initialization of a list is same as for a vector:
Using array:
```
int arr[] = {1, 2, 3};
std::list<int> lst(arr, arr + 3);
```
Using **push_back()**:
```
std::list<int> lst;
lst.push_back(1);
lst.push_back(2);
lst.push_back(3);
```
Using **fill constructor**:
```
std::list<int> lst(4, 7);   // {7,7,7,7}
```

## std::forward_list
Similar to std::list, but is implemented as as singly-linked list. It lacks direct access to elements via index and only directly supports iterations in forward direction.
**since c++11**

## std::deque
Pronounced as "deck". Unlike std::vector (which saves memory as a continuous block), the deque stores 

## std::array
This container encapsulates fixed size arrays. std::arrays have a fixed size and do not manage the allocation of its elements through an allocator. Unlike a C-style array, it does not automatically decay to a pointer. 
**since c++11**

### std::hive
**since c++26**

# Associative containers
No need to handle them in the first exercise.

## std::set
Set is an associative container: contains a sorted set of unique objects of type **Key**. 



