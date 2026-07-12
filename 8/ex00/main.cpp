#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(i * 2);

    std::vector<int>::iterator it = easyfind(vec, 6);
    std::cout << "found in vector: " << *it << std::endl;

    try
    {
        easyfind(vec, 7);
    }
    catch (std::exception const &e)
    {
        std::cout << "vector: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    std::list<int>::iterator lit = easyfind(lst, 20);
    std::cout << "found in list: " << *lit << std::endl;

    try
    {
        easyfind(lst, 99);
    }
    catch (std::exception const &e)
    {
        std::cout << "list: " << e.what() << std::endl;
    }

    std::vector<int> dup;
    dup.push_back(9);
    dup.push_back(4);
    dup.push_back(1);
    dup.push_back(4);

    std::vector<int>::iterator dit = easyfind(dup, 4);
    std::cout << "first occurrence index: " << std::distance(dup.begin(), dit) << std::endl;

    std::vector<int> const constVec(dup);
    std::vector<int>::const_iterator cit = easyfind(constVec, 9);
    std::cout << "found in const vector: " << *cit << std::endl;

    try
    {
        easyfind(constVec, 123);
    }
    catch (std::exception const &e)
    {
        std::cout << "const vector: " << e.what() << std::endl;
    }

    return 0;
}
