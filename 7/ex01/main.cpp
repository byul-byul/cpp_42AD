#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(T const &value)
{
    std::cout << value << " ";
}

static void doubleInt(int &value)
{
    value *= 2;
}

int main(void)
{
    int ints[5] = {1, 2, 3, 4, 5};

    std::cout << "ints:          ";
    iter(ints, 5, print<int>);
    std::cout << std::endl;

    iter(ints, 5, doubleInt);
    std::cout << "ints doubled:  ";
    iter(ints, 5, print<int>);
    std::cout << std::endl;

    int const constInts[3] = {10, 20, 30};
    std::cout << "const ints:    ";
    iter(constInts, 3, print<int>);
    std::cout << std::endl;

    std::string words[3] = {"aaa", "bbb", "ccc"};
    std::cout << "strings:       ";
    iter(words, 3, print<std::string>);
    std::cout << std::endl;

    return 0;
}
