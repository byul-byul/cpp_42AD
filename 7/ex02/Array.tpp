#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(std::size_t n) : _data(n ? new T[n]() : NULL), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &other)
    : _data(other._size ? new T[other._size] : NULL), _size(other._size)
{
    for (std::size_t i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this == &other)
        return *this;

    T *newData = other._size ? new T[other._size] : NULL;
    for (std::size_t i = 0; i < other._size; i++)
        newData[i] = other._data[i];

    delete[] _data;
    _data = newData;
    _size = other._size;
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template <typename T>
T &Array<T>::operator[](std::size_t index)
{
    if (index >= _size)
        throw OutOfRangeException();
    return _data[index];
}

template <typename T>
T const &Array<T>::operator[](std::size_t index) const
{
    if (index >= _size)
        throw OutOfRangeException();
    return _data[index];
}

template <typename T>
std::size_t Array<T>::size() const
{
    return _size;
}

template <typename T>
char const *Array<T>::OutOfRangeException::what() const throw()
{
    return "Array: index out of range";
}

#endif
