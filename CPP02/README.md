
# CPP Module 02

1. [Ad-hoc polymorphism](#Ad-hoc-polymorphism)
2. [Operator Overloading](#Operator-Overloading)
3. [Orthodox Canonical Class Form](#Orthodox-Canonical-Class-Form)

## <a id="Ad-hoc-polymorphism">Ad-hoc polymorphism</a>
- Ad-hoc Polymorphism, also called as Overloading Ad-hoc Polymorphism allows functions having same name to act differently for different types. 
- For example: The + operator adds two integers and concatenates two strings.

More information about <a href="https://www.geeksforgeeks.org/ad-hoc-inclusion-parametric-coercion-polymorphisms/">polymorphism</a>.

## <a id="Operator-Overloading">Operator Overloading</a>
- In C++, Operator overloading is a compile-time polymorphism. It is an idea of giving special meaning to an existing operator in C++ without changing its original meaning.
- <b>Example:</b>
```
class A 
{
	statements;
};

int main()
{
	A a1, a2, a3;

	a3 = a1 + a2;

	return 0;
}
```
- In this example, we have 3 variables “a1”, “a2” and “a3” of type “class A”. Here we are trying to add two objects “a1” and “a2”, which are of user-defined type i.e. of type “class A” using the “+” operator. This is not allowed, because the addition operator “+” is predefined to operate only on built-in data types. But here, “class A” is a user-defined type, so the compiler generates an error. This is where the concept of “Operator overloading” comes in.
- Now, if the user wants to make the operator “+” add two class objects, the user has to redefine the meaning of the “+” operator such that it adds two class objects. This is done by using the concept of “Operator overloading”. So the main idea behind “Operator overloading” is to use C++ operators with class variables or class objects. Redefining the meaning of operators really does not change their original meaning; instead, they have been given additional meaning along with their existing ones.
```
#include <iostream>
using namespace std;

class Complex {
private:
	int real, imag;

public:
	Complex(int r = 0, int i = 0)
	{
		real = r;
		imag = i;
	}

	// This is automatically called when '+' is used with
	// between two Complex objects
	Complex operator+(Complex const& obj)
	{
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	void print() { cout << real << " + i" << imag << '\n'; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;
	c3.print();
}
```

More information on <a href="https://www.geeksforgeeks.org/operator-overloading-cpp/">operator overloading</a>.


| integer.h
```
#include <iostream>

class Integer
{
	private:
		int _n;
	public:
		Integer(int const n);
		~Integer(void);
		int getValue(void) const;
		Integer & operator=(Integer const & rhs);	// 'Integer&' to update (change) and return only
													// the copy of the current instance
													// as arguments also passed hidden current
													// instance 'this'
		Integer operatir+(Integer const & rhs) const;	// same way sent hidden current 'this'
														// nothing will be changed and new Integer
														// will be returned 
};

std::ostream & operator<<(std::ostream & o, Integer const & rhs);
```
| integer.cpp
```
#include "integer.h"

Integer::Integer(int const n) : _n(n)
{
	std::cout<<"Constructor called\n";
}

Integer::~Integer(void)
{
	std::cout<<"Destructor called\n";
}

int Integer: getValue(void) const
{
	return this->_n;
}

Integer & Integer::operator=(Integer const & rhs)
{
	this->_n = rhs.getValue();

	return *this;
}

Integer Integer::operatir+(Integer const & rhs) const
{
	return Integer(this->_n + rhs.getValue());
}

std::ostream & operator<<(std::ostream & o, Integer const & rhs)
{
	o << rhs.getValue();

	return o;
}
```

Source: <a href="https://42.fr/en/homepage/">42</a>.

## <a id="Orthodox-Canonical-Class-Form">Orthodox Canonical Class Form</a>

- <b>A default constructor:</b> used internally to initialize objects and data members when no other value is available.
- <b>A copy constructor:</b> used in the implementation of call-by-value parameters.
- <b>An assignment operator:</b> used to assign one value to another.
- <b>A destructor:</b> Invoked when an object is deleted.

