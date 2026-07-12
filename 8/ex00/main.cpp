#include <iostream>
#include <vector>
#include <list>
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

    return 0;
}
