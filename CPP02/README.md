
# CPP Module 02

1. [Ad-hoc polymorphism](#Ad-hoc-polymorphism)
2. [Operator Overloading](#Operator-Overloading)
3. [Orthodox Canonical Class Form](#Orthodox-Canonical-Class-Form)
4. [Additional info](#Additional-info)
5. [Static](#Static)


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

## <a id="Additional-info">Additional info</a>

### Bit shifting:
- One use is division or multiplication by integer powers of 2.
- A left shift of 'n' is the same as multiplying a value by 2^n, only much faster. Likewise a right shift is the same as dividing by 2^n.

### Fixed point 
- Converting from fixed-point to floating-point is straightforward. We take the input value and divide it by (2fractional_bits), putting the result into a double:
```
	inline double fixed_to_double(fixed_point_t input)
	{
		return ((double)input / (double)(1 << FIXED_POINT_FRACTIONAL_BITS));
	}
```
- To convert from floating-point to fixed-point, we follow this algorithm:
- 1. Calculate x = floating_input * 2^(fractional_bits)
- 2. Round x to the nearest whole number (e.g. round(x))
- 3. Store the rounded x in an integer container
```
	inline fixed_point_t double_to_fixed(double input)
	{
		return (fixed_point_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS)));
	}
```
<a href = "https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/">Source</a>
- The conversion from the integer format to the fixed point format is done by shifting 'n' positions to the left, so that the position of the binary point is correct.
<a href="https://www.codeproject.com/Articles/37636/Fixed-Point-Class">Source<a>

## <a id="Static">Static</a>
- We can define class members static using static keyword. When we declare a member of a class as static it means no matter how many objects of the class are created, there is only one copy of the static member.
- A static member is shared by all objects of the class. All static data is initialized to zero when the first object is created, if no other initialization is present. We can't put it in the class definition but it can be initialized outside the by redeclaring the static variable, using the scope resolution operator :: to identify which class it belongs to.

### Static Function Members
- By declaring a function member as static, you make it independent of any particular object of the class. A static member function can be called even if no objects of the class exist and the static functions are accessed using only the class name and the scope resolution operator ::.
- A static member function can only access static data member, other static member functions and any other functions from outside the class.
- Static member functions have a class scope and they do not have access to the this pointer of the class. You could use a static member function to determine whether some objects of the class have been created or not.