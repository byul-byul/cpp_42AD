#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cctype>
#include <sys/time.h>
#include "PmergeMe.hpp"

static bool parseNumber(std::string const &token, int &value)
{
    if (token.empty())
        return false;
    for (size_t i = 0; i < token.size(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(token[i])))
            return false;
    }

    long parsed = std::strtol(token.c_str(), NULL, 10);
    if (parsed > 2147483647L)
        return false;
    value = static_cast<int>(parsed);
    return true;
}

static double elapsedMicroseconds(struct timeval const &start, struct timeval const &end)
{
    double seconds = static_cast<double>(end.tv_sec - start.tv_sec);
    double micros = static_cast<double>(end.tv_usec - start.tv_usec);
    return seconds * 1000000.0 + micros;
}

static void printSequence(std::vector<int> const &values)
{
    for (size_t i = 0; i < values.size(); i++)
    {
        if (i)
            std::cout << " ";
        std::cout << values[i];
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; i++)
    {
        int value;
        if (!parseNumber(argv[i], value))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        input.push_back(value);
    }

    std::cout << "Before: ";
    printSequence(input);

    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);
    std::vector<int> sortedVector = PmergeMe::sortVector(input);
    gettimeofday(&end, NULL);
    double vectorTime = elapsedMicroseconds(start, end);

    std::cout << "After: ";
    printSequence(sortedVector);

    std::deque<int> deq(input.begin(), input.end());
    gettimeofday(&start, NULL);
    std::deque<int> sortedDeque = PmergeMe::sortDeque(deq);
    gettimeofday(&end, NULL);
    double dequeTime = elapsedMicroseconds(start, end);

    std::cout << "Time to process a range of " << input.size()
        << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << input.size()
        << " elements with std::deque : " << dequeTime << " us" << std::endl;

    return 0;
}
