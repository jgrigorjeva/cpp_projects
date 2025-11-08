# This exercise introduces exceptions

Exceptions represent unexpected issues that may occur during program execution. 
C++ provides a way to handle exceptions gracefully using a **try-catch block**. Some error-prone code is tested inside the try block, if a defined error occurs. **exceptions can be thrown**:

```
try {
    // Code that might fail or throw
    if (something_is_wrong)
        throw std::runtime_error("Something went wrong!");
}
```
The **try** **block** seeems to **need a catch block** inside the containing block. If there is none, just throw without the try block.

The std::runtime_error is a standard exception derived from the **std::exception base class**.


```
class exception {
public:

    exception() noexcept;
    exception(const exception&) noexcept;
    exception& operator=(const exception&) noexcept;
    
    virtual ~exception();
    virtual const char* what() const noexcept;
};
```

Standard exceptions are generally thrown by library components, so we as programmers should be aware of them and catch them.

**When an exception is thrown inside a try block, normal execution stops immediately at this point.** The control jumps to the first matching catch block, which receives the exception object and decides what to do next. For instance, the catch block can clean up resources, or report the error, or even throw another exception (or rethrow this one).

```
catch (const std::exception &e) {
    // Handle the error here
    std::cerr << "Error: " << e.what() << '\n';
}
```

Each catch block handles a specific type of exception, for instance:

```
try {
    if (x < 0)
        throw std::invalid_argument("Negative value not allowed");
    if (x == 0)
        throw std::runtime_error("Division by zero");
}
catch (const std::invalid_argument &e) {
    std::cerr << "Invalid input: " << e.what() << '\n';
}
catch (const std::runtime_error &e) {
    std::cerr << "Runtime error: " << e.what() << '\n';
}
catch (...) {
    std::cerr << "Unknown exception caught!\n";
}
```

**If an exception is thrown inside a constructor**, normal control flow stops. The program begins to destroy all already costructed subobjects of that class (base classes and members). After that, control jumps to the nearest matching catch block. The object was never constructed so no destructor is called to destroy it.
However, if a catch block (without rethrow) is present inside the constructor, the subobjects are not destroyed and the construction continues normally. So, the destruction happens only if the exception leaves the constructor.
**Better not to throw exceptions inside destructors** (unless the cath block is inside the destructor and does not rethrow). It will cause std::terminate() if another exception is active. The std::terminate() will terminate the program instantly.

## Custom exceptions
**1. derived from std::exception**

```
class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "My custom exception occurred!";
    }
};
```

The noexcept keyword means this method itself will not throw (from C++11).

**2. exceptions with the support of custom messages: e. g. deriving from std::runtime_error (stores a string message)**
```
class FileError : public std::runtime_error {
public:
    explicit FileError(const std::string& filename)
        : std::runtime_error("Failed to open file: " + filename) {}
};
```
The explicit keyword forbids implicit conversions like const char* -> std:string (they can be confusing)

```
int main() {
    try {
        throw FileError("data.txt");
    }
    catch (const FileError& e) {
        std::cerr << e.what() << '\n';
    }
}
```

***
## Random comments

**1. The exceptions are just regular c++ classes** that happen to be suitable for throwing and catching. It is the throw keybord that makes an exception event. Otherwise, we can construct them and use methods just like in other classes:

```
class FileError : public std::runtime_error {
public:
    explicit FileError(const std::string& filename)
        : std::runtime_error("File error: " + filename) {}
};

FileError e("config.txt");
std::cout << e.what() << '\n';
```



***
**2. I was using this class definition at home and it worked fine:**
```
class GradeTooHighException : public std::exception 
{
    public:
    const char* what();
};
```

But on school computers, it threw this compilation error: 
```
In file included from main.cpp:2:
./Bureaucrat.hpp:28:29: error: 'Bureaucrat::GradeTooHighException::what' hides overloaded virtual function [-Werror,-Woverloaded-virtual]
        virtual const char* what();
                            ^
/usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../include/c++/12/bits/exception.h:76:5: note: hidden overloaded virtual function 'std::exception::what' declared here: different qualifiers ('const' vs unqualified)
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
```
So, had to change the class definition to:
```
class GradeTooHighException : public std::exception 
{
    public:
    const char*		what() const throw();
};
```

***
**3. I keep forgetting this:**
```
Bureaucrat jane;
Bureaucrat jane2 = jane; //is equivalent to jane2(jane)
```

-> copy constructor is called to create jane2!
If we wanted to use copy assignment operator, the object would first be created (with parameters or not) and then assigned:
```
Bureaucrat jane3;
jane3 = jane;
```