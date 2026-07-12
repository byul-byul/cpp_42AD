#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(42);
    }
    catch (std::exception const &e)
    {
        std::cout << "full span: " << e.what() << std::endl;
    }

    std::vector<int> values;
    for (int i = 0; i < 5; i++)
        values.push_back(i * 100);

    Span rangeSpan = Span(5);
    rangeSpan.addRange(values.begin(), values.end());
    std::cout << rangeSpan.shortestSpan() << std::endl;
    std::cout << rangeSpan.longestSpan() << std::endl;

    Span emptySpan = Span(1);
    try
    {
        emptySpan.shortestSpan();
    }
    catch (std::exception const &e)
    {
        std::cout << "empty span: " << e.what() << std::endl;
    }

    Span oneNumberSpan = Span(1);
    oneNumberSpan.addNumber(42);
    try
    {
        oneNumberSpan.longestSpan();
    }
    catch (std::exception const &e)
    {
        std::cout << "single-element span: " << e.what() << std::endl;
    }

    srand(time(NULL));
    unsigned int const bigSize = 10000;
    Span bigSpan = Span(bigSize);
    for (unsigned int i = 0; i < bigSize; i++)
        bigSpan.addNumber(rand());
    std::cout << "big span shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "big span longest: " << bigSpan.longestSpan() << std::endl;

    return 0;
}
