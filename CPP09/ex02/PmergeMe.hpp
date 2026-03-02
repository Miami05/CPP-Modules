#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <cctype>
#include <utility>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;
    void parseInput(int argc, char **argv);
    static std::vector<int> buildInsertOrder(int n);
    void sortVector();
    void fjVec(std::vector<int>& v);
    static int lowerBoundVec(const std::vector<int>& v, int val, int hi);
    void sortDeque();
    void fjDeq(std::deque<int>& d);
    static int  lowerBoundDeq(const std::deque<int>& d, int val, int hi);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    void run(int argc, char **argv);
};

#endif
