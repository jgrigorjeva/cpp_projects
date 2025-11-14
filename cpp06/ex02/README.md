# This exercise uses the dynamic_cast
dynamic_cast can be used only with pointers and references to objects. Its purpose is to ensure that the result of the type conversion is a valid complete object of the requested class.

Therefore, dynamic_cast is always successful when we cast a class to one of its base classes. It is checked at runtime and returns nullptr if the cast is not valid.

```
Base* ptr = new Derived;
Derived* copy = dynamic_cast<Derived*>(ptr); //copy is not NULL in this case
```