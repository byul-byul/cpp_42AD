#include "Identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 0; i < 6; i++)
    {
        Base *p = generate();

        std::cout << "pointer form:   ";
        identify(p);
        std::cout << "reference form: ";
        identify(*p);
        std::cout << std::endl;

        delete p;
    }

    return 0;
}
