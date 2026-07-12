#include <algorithm>
#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(Span const &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span &Span::operator=(Span const &other)
{
    if (this == &other)
        return *this;
    _maxSize = other._maxSize;
    _numbers = other._numbers;
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int value)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span: full");
    _numbers.push_back(value);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Span: not enough numbers");

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int shortest = sorted[1] - sorted[0];
    for (std::vector<int>::size_type i = 2; i < sorted.size(); i++)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Span: not enough numbers");

    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    return *maxIt - *minIt;
}
