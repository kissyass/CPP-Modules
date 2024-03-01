// Develop a Span class that can store a maximum of N integers. N is an unsigned int
// variable and will be the only parameter passed to the constructor.
// This class will have a member function called addNumber() to add a single number
// to the Span. It will be used in order to fill it. Any attempt to add a new element if there
// are already N elements stored should throw an exception.
// Next, implement two member functions: shortestSpan() and longestSpan()
// They will respectively find out the shortest span or the longest span (or distance, if
// you prefer) between all the numbers stored, and return it. If there are no numbers stored,
// or only one, no span can be found. Thus, throw an exception.
// Of course, you will write your own tests and they will be way more thorough than the
// ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
// even better.

#include "Span.hpp"

Span :: Span(unsigned int size)
{
    this->size = size;
}

Span :: Span(const Span &copy)
{
    *this = copy;
}

Span & Span :: operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->size = copy.size;
        this->vec = copy.vec;
    }
    return *this;
}

Span :: ~Span(void){}

void Span :: addNumber(int n)
{
    if (this->vec.size() >= this->size)
        throw SpanIsFullException();
    this->vec.push_back(n);
}

int Span :: shortestSpan(void)
{
    if (this->vec.size() < 2)
        throw NotEnoughElementsException();
    std::sort(this->vec.begin(), this->vec.end());
    int shortest = this->vec[1] - this->vec[0];
    int diff;
    for (std::size_t i = 2; i < this->vec.size(); i++)
    {
        diff = this->vec[i] - this->vec[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return (shortest);
}

int Span :: longestSpan(void)
{
    if (this->vec.size() < 2)
        throw NotEnoughElementsException();
    return *std::max_element(this->vec.begin(), this->vec.end()) - *std::min_element(this->vec.begin(), this->vec.end());
}

const char * Span :: NotEnoughElementsException :: what() const throw()
{
    return ("Not enough elements to find a span");
}

const char * Span :: SpanIsFullException :: what() const throw()
{
    return ("Can't add an element, span is already full");
}

void Span :: addNumbers(T begin, T end)
{
    unsigned int size = std::distance(begin, end);
    if (size + this->vec.size() > this->size)
        throw TooBigArrayException();
    this->vec.insert(this->vec.end(), begin, end);
}

const char * Span :: TooBigArrayException :: what() const throw()
{
    return ("Can't add elements int the span, too much of them");
}

void Span :: print_span(void)
{
    for (unsigned int i = 0; i < this->vec.size(); i++)
        std::cout << this->vec[i] << " ";
}

