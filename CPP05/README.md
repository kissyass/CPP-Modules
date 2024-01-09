
# CPP Module 05

1. [Exceptions](#Exceptions)
2. [Virtual](#Virtual)
3. [Virtual Member Functions](#Virtual-Member-Functions)
4. [Pure Virtual Functions](#Pure-Virtual-Functions)


## <a id="Exceptions">Exceptions</a>
- When an error occurs, C++ will normally stop and generate an error message. The technical term for this is: C++ will throw an exception (throw an error).
- Exception handling in C++ consist of three keywords: try, throw and catch:
1. The <b>try</b> statement allows you to define a block of code to be tested for errors while it is being executed.
2. The <b>throw</b> keyword throws an exception when a problem is detected, which lets us create a custom error.
3. The <b>catch</b> statement allows you to define a block of code to be executed, if an error occurs in the try block.
- The try and catch keywords come in pairs

## Inheriting exception class and what kw
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade is too high"; }
    };

- <b>virtual</b>: Adds nothing, as the method being overridden is already virtual. You are correct: it can be omitted.
- <b>const char* what()</b>: A member function named what() that takes no arguments and returns a pointer to const char.
- <b>const</b>: The member function can be called via a const pointer or reference to an instance of this class or a derived class.
- <b>throw()</b>: Throws no exceptions.

- <b>what</b> keyword returns a null terminated character sequence that may be used to identify the exception.
<a href="https://stackoverflow.com/questions/22493294/what-is-the-meaning-of-this-header-virtual-const-char-what-const-throw">Source</a>
