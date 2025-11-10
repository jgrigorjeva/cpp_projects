# The Form class becomes abstract
### Reminder: an abstract class has at least one pure virtual function (uses the pure specifier =0), e. g.:

```
virtual int my_pure_virtual_fn() = 0;
```

### Reminder nr. 2: the destructor of a base clas has to be virtual. This is because when using polymorfism and creating the instance through a pointer like this:
```
Base* basePtr = new Derived();
```
**if the Base destructor is non-virtual**, only the destructor of Base gets called when **delete basePtr** is invoked. The Derived destructor is not called, potentially leaving any derived-class-specific resources undeleted.

If the derived object is created directly as 
```
Derived derived_obj;
```
then both destructors are called correctly even if the Base destructor is non-virtual. However, the polymorfism cannot be used in that case.

### Reminder nr 3: files are opened/created like this
```
std::string outFileName
std::ofstream outFile(outFileName.c_str()); // Open file for writing
if (!outFile) {
        std::cerr << "Error: Could not open " << outFileName << std::endl;
        return 1;
}
outFile << str << "\n"; // Write some string to output
outFile.close();
```
## ShrubberyCreationForm
This form is supposed to create a file and write an ASCII tree to it. A quick internet search reveals that an ASCII tree represents a tree folder structure. However, my assumption is that the subject means an ASCII art representing a tree. Anyways, the folder structure seems like a more interesting problem that lets me discover some more c++ functions, so here is my solution:
```
void ShrubberyCreationForm::_makeShrub(std::string &filename)
{
    std::string treeCMD = "tree --charset=ASCII  > ";
    std::string cmd = treeCMD + filename + "_shrubbery";
    std::system(cmd.c_str());
}
```

The int std::system(const char *cmd) calls the host environment's command processor (e.g. /bin/sh, cmd.exe) with the parameter command. Returns an implementation-defined value (usually the value that the invoked program returns). Does not need a child process. My command contains a redirection, so no need to create and open the target file.

### Reminder nr 4: When a derived class' copy constructor is defined like this
```
ShrubberyCreationForm(const ShrubberyCreationForm &);
```
i.e. it takes the reference to another ShrubberyCreationForm instance instead of the reference to AForm, then we need to cast, if instantiating like this:
```
AForm *shrub3 = new ShrubberyCreationForm(*dynamic_cast<ShrubberyCreationForm*>(shrub1));
```