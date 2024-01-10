
# CPP Module 06

1. [Static class](#Static-class)
2. [Additional functions](#Additional-functions)
3. [Convert types](#Convert-types) 


## <a id="Static-class">Static class</a>
- In C++, a "static class" has no meaning. The nearest thing is a class with only static methods and members.
- to make "static" class you can make all constructors private.

## <a id="Additional-functions">Additional functions</a>
- <b>str.c_str()</b> - Converts str std::string to a C-style string using c_str()
- <b>std::cout << std::fixed << std::setprecision(2) << float_number</b> - converts float number to fixed point number with specified (2) numbers after '.'

## <a id="Convert-types">Convert types</a>
- <b>static_cast<></b>: Used for general-purpose type conversions that are known at compile time.
- <b>reinterpret_cast<></b>: Used for low-level, unsafe conversions between pointer types or between pointer and integral types.
- <b>dynamic_cast<></b>: Used for safe runtime downcasting in polymorphic class hierarchies, where the base class has at least one virtual function.
