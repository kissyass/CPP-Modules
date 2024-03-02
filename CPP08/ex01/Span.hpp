#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int size;
        std::vector<int> vec;
        Span(void);
    public:
        Span(unsigned int size);
        Span(const Span &copy);
        Span & operator=(const Span &copy);
        ~Span(void);
        void addNumber(int n);
        int shortestSpan(void);
        int longestSpan(void);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void print_span(void);
        class NotEnoughElementsException : public std::exception 
        {
            public:
                char const* what() const throw();
        };
        class SpanIsFullException : public std::exception 
        {
            public:
                char const* what() const throw();
        };
        class TooBigArrayException : public std::exception 
        {
            public:
                char const* what() const throw();
        };
};

#endif
