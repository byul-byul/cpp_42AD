#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}

// Overload resolution prefers this one for const containers, since T::iterator
// would fail to bind to a const_iterator in the non-const version above.
template <typename T>
typename T::const_iterator easyfind(T const &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}

#endif
