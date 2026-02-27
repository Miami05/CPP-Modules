#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main() {
    std::cout << "=== MutantStack basic test ===\n";

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
    std::cout << "\nIterate forward:\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it)
        std::cout << *it << "\n";
    std::cout << "\nIterate reverse:\n";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    for (; rit != rite; ++rit)
        std::cout << *rit << "\n";
    std::stack<int> s(mstack);
    std::cout << "\nCopied into std::stack, top: " << s.top() << "\n";
        const MutantStack<int> cmstack = mstack;
    std::cout << "\nConst iterate forward:\n";
    MutantStack<int>::const_iterator cit = cmstack.begin();
    MutantStack<int>::const_iterator cite = cmstack.end();
    for (; cit != cite; ++cit)
        std::cout << *cit << "\n";

    return 0;
}
