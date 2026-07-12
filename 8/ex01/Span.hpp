#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class Span
{
    public:
        Span(unsigned int n);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span();

        void addNumber(int value);

        template <typename InputIterator>
        void addRange(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                addNumber(*first);
                ++first;
            }
        }

        int shortestSpan() const;
        int longestSpan() const;

    private:
        // Declared but never defined: disables default construction (a Span
        // without a capacity is meaningless) while still satisfying OCF.
        Span();

        unsigned int      _maxSize;
        std::vector<int>  _numbers;
};

#endif
