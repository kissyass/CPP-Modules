
# CPP Module 00

1. [Pointers](#Pointers)
2. [This Pointer](#This-Pointer)


## <a id="Pointers">Pointers</a>
- Pointers in C++: Pointers are a symbolic representation of addresses. They enable programs to simulate call-by-reference as well as to create and manipulate dynamic data structures.
- Syntax:
```
    datatype *var_name; 
    int *ptr;   
```

More information on <a href="https://www.geeksforgeeks.org/pointers-c-examples/">pointers</a>.

## <a id="This-Pointer">This Pointer</a>
- The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions. ‘
- this’ pointer is not available in static member functions as static member functions can be called without any object (with class name). Even if only one member of each function exists which is used by multiple objects, the compiler supplies an implicit pointer along with the names of the functions as ‘this’.
- Declaration: 
```
    this->x = x; 
```

More information on <a href="https://www.geeksforgeeks.org/this-pointer-in-c/">this pointer</a>.
