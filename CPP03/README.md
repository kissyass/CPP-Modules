
# CPP Module 03

1. [New and delete](#new-and-delete)
2. [Virtual](#Virtual)
3. [Virtual Member Functions](#Virtual-Member-Functions)
4. [Pure Virtual Functions](#Pure-Virtual-Functions)


## <a id="new-and-delete">New and delete</a>
- Using new and dynamic memory allocation provides more control over the object's lifetime but requires manual memory management. Using stack allocation (without new) is simpler and often safer, but the object's lifetime is tied to the scope where it is declared.

## <a id="Virtual">Virtual</a>
- It's important to note that when using polymorphism in C++, if a base class has virtual functions, it's recommended to declare its destructor as virtual as well to ensure proper cleanup of resources when deleting objects through base class pointers. 
- Note the use of the virtual keyword in the makeSound function in the base class (Animal). This allows dynamic dispatch, ensuring that the correct version of makeSound is called based on the actual type of the object being pointed to.

## <a id="Virtual-Member-Functions">Virtual Member Functions</a>
### Definition:
- A virtual function is a member function of a class that is declared with the virtual keyword in the base class.
Virtual functions are intended to be overridden by derived classes.
### Purpose:
- Virtual functions provide a way to achieve runtime polymorphism. They allow a program to call the correct version of a function based on the actual type of an object at runtime.
### Syntax:
```
class Base {
public:
    virtual void virtualFunction() {
        // Base class implementation
    }
};
```
### Override in Derived Classes:
```
class Derived : public Base {
public:
    void virtualFunction() override {
        // Derived class implementation
    }
};
```
### Dynamic Dispatch:
- When a base class pointer (or reference) is used to access a derived class object, and a virtual function is called through that pointer, the correct version of the function in the derived class is executed.
- This is known as dynamic dispatch, and it allows for polymorphic behavior.
### Example:
```
Base* ptr = new Derived();  // Using base class pointer to point to a derived class object
ptr->virtualFunction();    // Calls the overridden function in the derived class
delete ptr;                // Important to delete, and the correct destructor will be called
```

## <a id="Pure-Virtual-Functions">Pure Virtual Functions</a>
- A pure virtual function is a virtual function that is declared in a base class but has no implementation. It is marked with = 0.
- Classes containing pure virtual functions are abstract classes, and they cannot be instantiated. Derived classes must provide an implementation for pure virtual functions.
```
class AbstractBase {
public:
    virtual void pureVirtualFunction() = 0;  // Pure virtual function
};
```
- Derived classes must implement the pure virtual function:
```
class ConcreteDerived : public AbstractBase {
public:
    void pureVirtualFunction() override {
        // Implementation of the pure virtual function
    }
};
```