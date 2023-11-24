
# CPP Module 01

1. [New and delete](#new-and-delete)
2. [References](#references)
3. [Filestream](#filestream)
4. [References vs Pointers](#references-vs-pointers)
5. [Useful functions](#Useful-functions)
6. [Pointers to member functions](#Pointers-to-member-functions)

## <a id="new-and-delete">New and delete</a>
- Dynamic memory allocation in C/C++ refers to performing memory allocation manually by a programmer. 
- Dynamically allocated memory is allocated on <b>Heap</b>, and non-static and local variables get memory allocated on <b>Stack</b>
- To allocate heap memory in C++, use the keyword new followed by the constructor of what you want to allocate.
### How is it different from memory allocated to normal variables? 
- For normal variables like “int a”, “char str[10]”, etc, memory is automatically allocated and deallocated. For dynamically allocated memory like “int *p = new int[10]”, it is the programmer’s responsibility to deallocate memory when no longer needed. If the programmer doesn’t deallocate memory, it causes a memory leak (memory is not deallocated until the program terminates). 
### New operator 
- The new operator denotes a request for memory allocation on the Free Store. If sufficient memory is available, a new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable. 
- Syntax:
```
    pointer-variable = new data-type;
    int *p = new int; 
```
### Delete operator
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
### Applications of Reference in C++
- Modify the passed parameters in a function (e.g. for swap function)
- Avoiding a copy of large structures
- In For Each Loop to modify all objects
- For Each Loop to avoid the copy of objects

### There are 3 ways to pass C++ arguments to a function:
- call-by-value
- call-by-reference with a pointer argument
- call-by-reference with a reference argument

More information on <a href = "https://www.geeksforgeeks.org/references-in-cpp/">reference</a>
## <a id="Filestream">Filestream</a>
- To read and write from a file we are using the standard C++ library called fstream. Let us see the data types define in <b>fstream</b> library is:

|Data Type|Description|
|------|--------|
|fstream|It is used to create files, write information to files, and read information from files.|
|ifstream|It is used to read information from files.|
|ofstream|It is used to create files and write information to the files.|

### Example

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
## <a id="References-vs-Pointers">References vs Pointers</a>
Both references and pointers can be used to change the local variables of one function inside another function. Both of them can also be used to save copying of big objects when passed as arguments to functions or returned from functions, to get efficiency gain. Despite the above similarities, there are the following differences between references and pointers.
- A pointer can be declared as void but a reference can never be void For example
- The pointer variable has n-levels/multiple levels of indirection i.e. single-pointer, double-pointer, triple-pointer. Whereas, the reference variable has only one/single level of indirection. The following code reveals the mentioned points:  
- Reference variables cannot be updated.
- Reference variable is an internal pointer.
- Declaration of a Reference variable is preceded with the ‘&’ symbol ( but do not read it as “address of”).
- Once a reference is created, it cannot be later made to reference another object; it cannot be reset. This is often done with pointers. 
- References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing. 
- A reference must be initialized when declared. There is no such restriction with pointers.

|Parameters	|Pass by Pointer |Pass by Reference|
|----|-----|-----|
|Passing Arguments |We pass the address of arguments in the function call.	|We pass the arguments in the function call.|
|Accessing Values|The value of the arguments is accessed via the dereferencing operator *	|The reference name can be used to implicitly reference a value.|
|Reassignment|Passed parameters can be moved/reassigned to a different memory location.	|Parameters can’t be moved/reassigned to another memory address.|
|Allowed Values|Pointers can contain a NULL value, so a passed argument may point to a NULL or even a garbage value.|References cannot contain a NULL value, so it is guaranteed to have some value.|

### Which is preferred, Passing by Pointer Vs Passing by Reference in C++? 
- References are usually preferred over pointers whenever we don’t need “reseating”.
- If we want to use NULL in our function arguments, prefer pointers.
- Overall, <b>Use references when you can, and pointers when you have to</b>

More information on <a href = "https://www.geeksforgeeks.org/references-in-cpp/">reference vs pointer</a>

## <a id="Useful-functions">Useful functions</a>

### String find
- String find is used to find the first occurrence of a sub-string in the specified string being called upon. It returns the index of the first occurrence of the substring in the string from the given starting position. The default value of starting position is 0.
- <b>Syntax:</b>
```
size_t find (const string& str, size_t pos = 0); // for C++ Style Strings
         or
size_t find (const char* s, size_t pos = 0);     // for C-Style Strings
```
- <b>Parameters:</b>
- str: The sub-string to be searched.
- s: The sub-string to be searched, given as a C-style string.
- pos: The initial position from where the string search is to begin.
- <b>Return Value:</b>
- The function returns the index of the first occurrence of the sub-string.
- If the sub-string is not found it returns string::npos(string::pos is a static member with its value as the highest possible for the size_t data type).
- <b>Complexity analysis:</b>
- Time Complexity: O(N*M), where N is the size of the string(str) and M is the size of the substring to be searched.
- Auxiliary Space: O(1) 

More inforamtion on <a href="https://www.geeksforgeeks.org/string-find-in-cpp/">string find</a>.

### Substr
- The substring function is used for handling string operations like strcat(), append(), etc. It generates a new string with its value initialized to a copy of a sub-string of this object. In C++, the header file which is required for  std::substr(), string functions is <string>. 
- The substring function takes two values pos and len as an argument and returns a newly constructed string object with its value initialized to a copy of a sub-string of this object. Copying of string starts from pos and is done till pos+len means (pos, pos+len).
- <b>Syntax:</b> 
- string substr (size_t pos, size_t len) const;
- <b>Parameters:</b>
- pos: Position of the first character to be copied.
- len: Length of the sub-string.
- size_t: It is an unsigned integral type.
- <b>Return Value:</b> It returns a string object.

More inforamtion on <a href="https://www.geeksforgeeks.org/substring-in-cpp/">sub-strings</a>.

### c_str()
- The c_str() function in C++ converts a string to an array of characters and terminates this array with a null character at the end.
- The function does not accept any parameters. It returns a pointer to this array of characters.
- The c_str() function in C++ converts a given string to an array of characters.

More inforamtion on <a href="https://www.scaler.com/topics/cpp-string-c-str-function/">c_str()</a>.

## <a id="Pointers-to-member-functions">Pointers to member functions</a>

- You can compare pointers to member functions, assign values to them, and use them to call member functions. Note that a member function does not have the same type as a nonmember function that has the same number and type of arguments and the same return type.

More information on <a href="https://www.ibm.com/docs/en/i/7.4?topic=only-pointers-members-c">pointers to members</a> and <a href="https://isocpp.org/wiki/faq/pointers-to-members">FAQ</a>.
