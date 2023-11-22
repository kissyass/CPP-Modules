
# CPP Module 00

1. [New and delete](#new-and-delete)
2. [References](#references)
3. [Filestream](#filestream)
4. [References vs Pointers](#references-vs-pointers)


## <a id="new_delete">New and delete</a>
- Dynamic memory allocation in C/C++ refers to performing memory allocation manually by a programmer. 
- Dynamically allocated memory is allocated on <b>Heap</b>, and non-static and local variables get memory allocated on <b>Stack</b>
- To allocate heap memory in C++, use the keyword new followed by the constructor of what you want to allocate.
#### How is it different from memory allocated to normal variables? 
- For normal variables like “int a”, “char str[10]”, etc, memory is automatically allocated and deallocated. For dynamically allocated memory like “int *p = new int[10]”, it is the programmer’s responsibility to deallocate memory when no longer needed. If the programmer doesn’t deallocate memory, it causes a memory leak (memory is not deallocated until the program terminates). 
#### New operator 
- The new operator denotes a request for memory allocation on the Free Store. If sufficient memory is available, a new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable. 
- Syntax:
```
    pointer-variable = new data-type;
    int *p = new int; 
```
#### Delete operator
- Since it is the programmer’s responsibility to deallocate dynamically allocated memory, programmers are provided delete operator in C++ language. 
- Syntax:
```
    delete pointer-variable;  
    delete p;
```
More information on <a href = "https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/">new and delete</a>

## <a id="References">References</a>
- When a variable is declared as a reference, it becomes an alternative name for an existing variable. A variable can be declared as a reference by putting ‘&’ in the declaration. 
- Syntax:
```
    data_type &ref = variable;
```
#### Applications of Reference in C++
- Modify the passed parameters in a function (e.g. for swap function)
- Avoiding a copy of large structures
- In For Each Loop to modify all objects
- For Each Loop to avoid the copy of objects

More information on <a href = "https://www.geeksforgeeks.org/references-in-cpp/">reference</a>
## <a id="Filestream">Filestream</a>
- To read and write from a file we are using the standard C++ library called fstream. Let us see the data types define in <b>fstream</b> library is:

|Data Type|Description|
|------|--------|
|fstream|It is used to create files, write information to files, and read information from files.|
|ifstream|It is used to read information from files.|
|ofstream|It is used to create files and write information to the files.|

#### Example

```
#include <iostream>  
#include <fstream>  
int main () 
{  
    std::string input;  
    std::ofstream os;  
    os.open("testout.txt");  
    std::cout <<"Writing to a text file:" << std::endl;  
    std::cout << "Please Enter your name: ";   
    std::getline(std::cin, input);  
    os << input << std::endl;  
    std::cout << "Please Enter your age: ";   
    std::getline(std::cin, input); 
    os.close();  
    std::ifstream is;   
    std::string line;  
    is.open("testout.txt");   
    std::cout << "Reading from a text file:" << std::endl;   
    while (getline (is,line))  
    {  
    std::cout << line << std::endl;  
    }      
    is.close();  
    return 0;   
}  
```
More information on <a href = "https://www.javatpoint.com/cpp-files-and-streams">file streams</a>
## <a id="References_vs_Pointers">References vs Pointers</a>
Both references and pointers can be used to change the local variables of one function inside another function. Both of them can also be used to save copying of big objects when passed as arguments to functions or returned from functions, to get efficiency gain. Despite the above similarities, there are the following differences between references and pointers.
- A pointer can be declared as void but a reference can never be void For example
- The pointer variable has n-levels/multiple levels of indirection i.e. single-pointer, double-pointer, triple-pointer. Whereas, the reference variable has only one/single level of indirection. The following code reveals the mentioned points:  
- Reference variables cannot be updated.
- Reference variable is an internal pointer.
- Declaration of a Reference variable is preceded with the ‘&’ symbol ( but do not read it as “address of”).
- Once a reference is created, it cannot be later made to reference another object; it cannot be reset. This is often done with pointers. 
- References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing. 
- A reference must be initialized when declared. There is no such restriction with pointers.

More information on <a href = "https://www.geeksforgeeks.org/references-in-cpp/">reference vs pointer</a>



