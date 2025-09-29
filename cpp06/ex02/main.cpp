#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int random = rand() % 3;

    switch (random)
    {
        case 0:
            std::cout << "A generated" << std::endl;
            return new A();
        case 1:
            std::cout << "B generated" << std::endl;
            return new B();
        case 2:
            std::cout << "C generated" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A identified" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B identified" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C identified" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A identified" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B identified" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C identified" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    std::cout << "Unknown type" << std::endl;
}

int main(void)
{
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        Base* base = generate();
        identify(base);
        identify(*base);
        delete base;
    }

    return 0;
}