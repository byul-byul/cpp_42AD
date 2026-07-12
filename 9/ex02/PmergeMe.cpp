#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe()
{
}

// Ford-Johnson (merge-insertion) sort, operating on indices into `values`
// so that duplicate values never break the winner/loser bookkeeping.
std::vector<int> PmergeMe::mergeInsertVector(std::vector<int> const &values, std::vector<int> idx)
{
    size_t n = idx.size();
    if (n <= 1)
        return idx;

    bool odd = (n % 2 != 0);
    int straggler = 0;
    if (odd)
    {
        straggler = idx.back();
        idx.pop_back();
        n--;
    }

    // Pair up consecutive elements and compare each pair once: the larger
    // of the two (the "winner") goes on to be recursively sorted, while
    // loserOf[winner] remembers its paired "loser" so it can be reinserted
    // later without ever comparing the same pair twice.
    std::vector<int> loserOf(values.size(), -1);
    std::vector<int> winners;
    for (size_t i = 0; i < n; i += 2)
    {
        int a = idx[i];
        int b = idx[i + 1];
        if (values[a] < values[b])
        {
            loserOf[b] = a;
            winners.push_back(b);
        }
        else
        {
            loserOf[a] = b;
            winners.push_back(a);
        }
    }

    std::vector<int> chain = mergeInsertVector(values, winners);

    // `chain` is the winners in sorted order, so appending chain[j] to the
    // back is always correct: every element already in `result` is a
    // smaller winner or one of its losers, hence smaller than chain[j].
    // Its own loser is inserted first, via binary search bounded by
    // result.size() *before* chain[j] is appended - that upper bound is
    // exactly the count of elements already proven smaller than chain[j],
    // which is what keeps this insertion close to the Ford-Johnson optimal
    // comparison count instead of degrading into a plain insertion sort.
    std::vector<int> result;
    for (size_t j = 0; j < chain.size(); j++)
    {
        int loserIdx = loserOf[chain[j]];
        int lo = 0;
        int hi = static_cast<int>(result.size());
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (values[result[mid]] < values[loserIdx])
                lo = mid + 1;
            else
                hi = mid;
        }
        result.insert(result.begin() + lo, loserIdx);
        result.push_back(chain[j]);
    }

    // The odd element left out at the top has no pair/winner, so it is
    // inserted last with a plain binary search over the final sequence.
    if (odd)
    {
        int lo = 0;
        int hi = static_cast<int>(result.size());
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (values[result[mid]] < values[straggler])
                lo = mid + 1;
            else
                hi = mid;
        }
        result.insert(result.begin() + lo, straggler);
    }

    return result;
}

// Same Ford-Johnson logic as mergeInsertVector above (see its comments for
// why the loser/winner split and the bounded binary search are correct),
// but the order/index bookkeeping (idx, winners, chain, result) is kept in
// a std::deque instead of a std::vector, as required by the subject.
// `values` itself stays a plain vector: it is indexed by the *original*
// position of each element and never reordered, so its container type is
// independent of which container is used to sort those indices.
std::deque<int> PmergeMe::mergeInsertDeque(std::vector<int> const &values, std::deque<int> idx)
{
    size_t n = idx.size();
    if (n <= 1)
        return idx;

    bool odd = (n % 2 != 0);
    int straggler = 0;
    if (odd)
    {
        straggler = idx.back();
        idx.pop_back();
        n--;
    }

    std::vector<int> loserOf(values.size(), -1);
    std::deque<int> winners;
    for (size_t i = 0; i < n; i += 2)
    {
        int a = idx[i];
        int b = idx[i + 1];
        if (values[a] < values[b])
        {
            loserOf[b] = a;
            winners.push_back(b);
        }
        else
        {
            loserOf[a] = b;
            winners.push_back(a);
        }
    }

    std::deque<int> chain = mergeInsertDeque(values, winners);

    std::deque<int> result;
    for (size_t j = 0; j < chain.size(); j++)
    {
        int loserIdx = loserOf[chain[j]];
        int lo = 0;
        int hi = static_cast<int>(result.size());
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (values[result[mid]] < values[loserIdx])
                lo = mid + 1;
            else
                hi = mid;
        }
        result.insert(result.begin() + lo, loserIdx);
        result.push_back(chain[j]);
    }

    if (odd)
    {
        int lo = 0;
        int hi = static_cast<int>(result.size());
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (values[result[mid]] < values[straggler])
                lo = mid + 1;
            else
                hi = mid;
        }
        result.insert(result.begin() + lo, straggler);
    }

    return result;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> const &input)
{
    std::vector<int> idx(input.size());
    for (size_t i = 0; i < idx.size(); i++)
        idx[i] = static_cast<int>(i);

    std::vector<int> order = mergeInsertVector(input, idx);

    std::vector<int> result;
    result.reserve(order.size());
    for (size_t i = 0; i < order.size(); i++)
        result.push_back(input[order[i]]);
    return result;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> const &input)
{
    std::vector<int> values(input.begin(), input.end());
    std::deque<int> idx;
    for (size_t i = 0; i < values.size(); i++)
        idx.push_back(static_cast<int>(i));

    std::deque<int> order = mergeInsertDeque(values, idx);

    std::deque<int> result;
    for (size_t i = 0; i < order.size(); i++)
        result.push_back(values[order[i]]);
    return result;
}
