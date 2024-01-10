#include "./Serialization.hpp"

Serialization :: Serialization(void)
{}

Serialization :: Serialization(const Serialization &copy)
{
    (void)copy;
}

Serialization& Serialization :: operator=(const Serialization &rhs)
{
    (void)rhs;
    return *this;
}

Serialization :: ~Serialization(void)
{}

uintptr_t Serialization :: serialize(Data *ptr)
{
    std::cout << "Serialization is in progress..." << std::endl;
    ptr->name = "Yasmin";
    ptr->surname = "Kissikova";
    ptr->age = 22;
    std::cout << "Data ptr address: " << ptr << std::endl;
    std::cout << "Data ptr info: " << ptr->name << " " << ptr->surname << " " << ptr->age << std::endl;
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr); // reinterpret_cast is designed for this kind of low-level casting, especially when converting between pointers and integers.
    std::cout << "Raw data ptr: " << raw << std::endl;
    std::cout << "Serialization is done" << std::endl;
    return raw;
}

Serialization::Data * Serialization :: deserialize(uintptr_t raw)
{
    Data *ptr;

    std::cout << "Deserialization is in progress..." << std::endl;
    ptr = reinterpret_cast<Data *>(raw);
    std::cout << "Data ptr address: " << ptr << std::endl;
    std::cout << "Data ptr info: " << ptr->name << " " << ptr->surname << " " << ptr->age << std::endl;
    std::cout << "Deserialization is done" << std::endl;

    return ptr;
}

void Serialization :: run(void)
{
    uintptr_t raw;
    Data *data = new Data;
    Data *data2;
    raw = serialize(data);
    std::cout << "-----------------------------------------------" << std::endl;
    data2 = deserialize(raw);
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Raw data ptr: " << raw << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~Data 1 info~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Data ptr address: " << data << std::endl;
    std::cout << "Data ptr info: " << data->name << " " << data->surname << " " << data->age << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~Data 2 info~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Data ptr address: " << data2 << std::endl;
    std::cout << "Data ptr info: " << data2->name << " " << data2->surname << " " << data2->age << std::endl;
    delete data;
}