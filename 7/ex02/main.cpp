#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    // default constructor must produce an empty array
    Array<int> empty;
    if (empty.size() != 0)
    {
        std::cerr << "default constructor: size should be 0!!" << std::endl;
        return 1;
    }

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    if (numbers.size() != static_cast<std::size_t>(MAX_VAL))
    {
        std::cerr << "size(): wrong size after construction!!" << std::endl;
        return 1;
    }

    // copy construction must give an independent copy: modifying the
    // copies here must not be visible through the original 'numbers'
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        tmp[0] = -1;
        test[0] = -1;
        if (numbers[0] == -1)
        {
            std::cerr << "copy construction: modifying the copy affected the original!!" << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // assignment operator must deep-copy as well: neither side may affect
    // the other after the assignment
    Array<int> assigned;
    assigned = numbers;
    if (assigned.size() != numbers.size())
    {
        std::cerr << "operator=: size mismatch after assignment!!" << std::endl;
        return 1;
    }
    assigned[0] = -1;
    if (numbers[0] == -1)
    {
        std::cerr << "operator=: modifying the copy affected the original!!" << std::endl;
        return 1;
    }
    numbers[1] = -1;
    if (assigned[1] == -1)
    {
        std::cerr << "operator=: modifying the original affected the copy!!" << std::endl;
        return 1;
    }

    try
    {
        // -2 as a signed int wraps around to a huge std::size_t once
        // converted, so it must be rejected just like a too-large index
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
