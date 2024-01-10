#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

class Serialization
{
    private:
        Serialization(void);
        Serialization(const Serialization &copy);
        Serialization& operator=(const Serialization &rhs);
        ~Serialization(void);

        struct Data;
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
    public:
        static void run(void);
};

struct Serialization::Data
{
    std::string name;
    std::string surname;
    int age;
};

#endif