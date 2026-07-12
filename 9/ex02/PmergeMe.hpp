#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class PmergeMe
{
    public:
        static std::vector<int> sortVector(std::vector<int> const &input);
        static std::deque<int> sortDeque(std::deque<int> const &input);

    private:
        PmergeMe();
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();

        static std::vector<int> mergeInsertVector(std::vector<int> const &values, std::vector<int> idx);
        static std::deque<int> mergeInsertDeque(std::vector<int> const &values, std::deque<int> idx);
};

#endif
