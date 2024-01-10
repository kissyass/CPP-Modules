#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{}

Base * generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;

    switch (i)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Type of the pointer: A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Type of the pointer: B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Type of the pointer: C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p); //will throw an exception if refs are with diffrent types
        std::cout << "Type of the reference: A" << std::endl;
        (void)a;
        return ;
    }
    catch(const std::bad_cast& e)
    {}
    
    try
    {
        B &b = dynamic_cast<B&>(p); //will throw an exception if refs are with diffrent types
        std::cout << "Type of the reference: B" << std::endl;
        (void)b;
        return ;
    }
    catch(const std::bad_cast& e)
    {}

    try
    {
        C &c = dynamic_cast<C&>(p); //will throw an exception if refs are with diffrent types
        std::cout << "Type of the reference: C" << std::endl;
        (void)c;
        return ;
    }
    catch(const std::bad_cast& e)
    {
        std::cout << "Unknown type" << std::endl;
    }
    
}