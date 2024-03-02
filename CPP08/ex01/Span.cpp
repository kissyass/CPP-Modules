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

void Span :: addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    unsigned int size = std::distance(begin, end);
    if (size + this->vec.size() > this->size)
        throw TooBigArrayException();
    this->vec.insert(this->vec.end(), begin, end);
}

void Span :: print_span(void)
{
    for (unsigned int i = 0; i < this->vec.size(); i++)
        std::cout << this->vec[i] << " ";
}

const char * Span :: NotEnoughElementsException :: what() const throw()
{
    return ("Not enough elements to find a span");
}

const char * Span :: SpanIsFullException :: what() const throw()
{
    return ("Can't add an element, span is already full");
}

const char * Span :: TooBigArrayException :: what() const throw()
{
    return ("Can't add elements int the span, too much of them");
}
