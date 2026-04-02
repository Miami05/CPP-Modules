#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main() {

    std::cout << "=== MutantStack subject test ===\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << "\n";
    mstack.pop();
    std::cout << "size after pop: " << mstack.size() << "\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nForward iteration:\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it)
        std::cout << *it << "\n";

    std::cout << "\n=== Same test with std::list ===\n";
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    for (; lit != lite; ++lit)
        std::cout << *lit << "\n";

    std::cout << "\n=== Reverse iteration ===\n";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    for (; rit != rite; ++rit)
        std::cout << *rit << "\n";

    std::cout << "\n=== Const iteration ===\n";
    const MutantStack<int> cmstack = mstack;
    MutantStack<int>::const_iterator cit = cmstack.begin();
    MutantStack<int>::const_iterator cite = cmstack.end();
    for (; cit != cite; ++cit)
        std::cout << *cit << "\n";

    std::cout << "\n=== Empty stack test ===\n";
    MutantStack<int> empty;
    std::cout << "is empty: " << empty.empty() << "\n";
    empty.push(42);
    std::cout << "after push, empty: " << empty.empty() << "\n";
    std::cout << "size: " << empty.size() << "\n";

    std::cout << "\n=== Copy constructor test ===\n";
    MutantStack<int> copy(mstack);
    std::cout << "copy top: " << copy.top() << "\n";
    std::cout << "copy size: " << copy.size() << "\n";

    std::cout << "\n=== Assignment operator test ===\n";
    MutantStack<int> assigned;
    assigned = mstack;
    std::cout << "assigned top: " << assigned.top() << "\n";

    std::cout << "\n=== Copy to std::stack test ===\n";
    std::stack<int> s(mstack);
    std::cout << "std::stack top: " << s.top() << "\n";

    std::cout << "\n=== String type test ===\n";
    MutantStack<std::string> sstack;
    sstack.push("hello");
    sstack.push("42");
    sstack.push("world");
    MutantStack<std::string>::iterator sit = sstack.begin();
    MutantStack<std::string>::iterator site = sstack.end();
    for (; sit != site; ++sit)
        std::cout << *sit << "\n";

    return 0;
}
