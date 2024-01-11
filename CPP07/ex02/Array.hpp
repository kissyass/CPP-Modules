#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *_vals;
        unsigned int _size;
    public:
        Array(void) : _vals(NULL), _size(0) {}

        Array(Array const &copy) : _vals(new T[copy._size]), _size(copy._size)
        {
            for (unsigned int i = 0; i < copy._size; i++)
                this->_vals[i] = copy._vals[i];
        }

        Array & operator=(Array const &rhs)
        {
            if (this != &rhs)
            {   
                if (this->_vals != NULL)
                   delete [] this->_vals;
                this->_size = rhs._size;
                this->_vals = new T[this->_size];
                for (unsigned int i = 0; i < rhs._size; i++)
                    this->_vals[i] = rhs._vals[i];
            }
            return *this;
        }

        ~Array(void)
        {
            if (this->_vals != NULL)
                delete [] this->_vals;
        }

        Array(unsigned int len) : _vals(new T[len]), _size(len) {}

        T & operator[](unsigned int in) const
        {
            if (in >= this->_size)
                throw InvalidIndex();
            return this->_vals[in];
        }

        unsigned int size(void) const
            {return this->_size;}

        class  InvalidIndex : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {return "Index is out of range";}
        };
};

#endif