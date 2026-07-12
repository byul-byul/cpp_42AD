#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
    public:
        Array();
        explicit Array(std::size_t n);
        Array(Array const &other);
        Array &operator=(Array const &other);
        ~Array();

        T &operator[](std::size_t index);
        T const &operator[](std::size_t index) const;
        std::size_t size() const;

        class OutOfRangeException : public std::exception
        {
            public:
                virtual char const *what() const throw();
        };

    private:
        T           *_data;
        std::size_t _size;
};

# include "Array.tpp"

#endif
