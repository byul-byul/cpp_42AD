#include <iostream>
#include <stack>
#include <list>
#include <sstream>
#include <cassert>
#include "MutantStack.hpp"

// Verbatim example from the subject: sanity check that a MutantStack
// behaves like an std::stack and is iterable on top of that.
static void subjectExample()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    (void)s;
}

// Same sequence of operations run on a MutantStack and on an std::list,
// as the subject suggests ("push() can become push_back()"). Iteration
// order, pop() semantics and the final content must match.
static void compareAgainstList()
{
    MutantStack<int> mstack;
    std::list<int> reference;

    int const values[] = {5, 17, 3, 5, 737, 0, -12, 42};
    size_t const count = sizeof(values) / sizeof(values[0]);

    for (size_t i = 0; i < count; i++)
    {
        mstack.push(values[i]);
        reference.push_back(values[i]);
    }

    mstack.pop();
    mstack.pop();
    reference.pop_back();
    reference.pop_back();

    std::ostringstream mstackDump;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        mstackDump << *it << " ";

    std::ostringstream listDump;
    for (std::list<int>::iterator it = reference.begin(); it != reference.end(); ++it)
        listDump << *it << " ";

    assert(mstackDump.str() == listDump.str());
    assert(mstack.size() == reference.size());
    assert(mstack.top() == reference.back());
    std::cout << "MutantStack vs std::list: " << mstackDump.str() << std::endl;
}

static void constIteratorAndEmptyStack()
{
    MutantStack<int> mstack;

    assert(mstack.begin() == mstack.end());

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    MutantStack<int> const &constRef = mstack;
    std::ostringstream dump;
    for (MutantStack<int>::const_iterator it = constRef.begin(); it != constRef.end(); ++it)
        dump << *it << " ";
    std::cout << "const_iterator: " << dump.str() << std::endl;
}

static void copyAndAssignment()
{
    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);

    MutantStack<int> copy(original);
    assert(copy.size() == original.size());
    assert(copy.top() == original.top());

    MutantStack<int> assigned;
    assigned.push(99);
    assigned = original;
    assert(assigned.size() == original.size());
    assert(assigned.top() == original.top());

    original.pop();
    assert(copy.size() != original.size());
    std::cout << "copy/assignment: independent storage confirmed" << std::endl;
}

int main()
{
    subjectExample();
    compareAgainstList();
    constIteratorAndEmptyStack();
    copyAndAssignment();
    return 0;
}
