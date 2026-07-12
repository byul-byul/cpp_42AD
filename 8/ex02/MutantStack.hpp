#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator       iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        MutantStack();
        MutantStack(MutantStack const &other);
        MutantStack &operator=(MutantStack const &other);
        ~MutantStack();

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
};

# include "MutantStack.tpp"

#endif
