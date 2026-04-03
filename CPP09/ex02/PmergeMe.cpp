#include "PmergeMe.hpp"
#include <iostream>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; i++)
    {
        std::string token(argv[i]);
        if (token.empty())
            throw std::runtime_error("Error");
        for (size_t j = 0; j < token.size(); j++)
        {
            if (!isdigit(static_cast<unsigned char>(token[j])))
                throw std::runtime_error("Error");
        }
        long val = 0;
        for (size_t j = 0; j < token.size(); ++j)
        {
            val = val * 10 + (token[j] - '0');
            if (val > 2147483647L)
                throw std::runtime_error("Error");
        }
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
    if (_vec.empty())
        throw std::runtime_error("Error");
}

std::vector<int> PmergeMe::buildInsertOrder(int n) {
    if (n <= 0)
        return std::vector<int>();
    std::vector<int> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < n)
    {
        int sz = static_cast<int>(jac.size());
        jac.push_back(jac[sz - 1] + 2 * jac[sz - 2]);
    }
    std::vector<int> order;
    order.reserve(n);
    for (int k = 1; static_cast<int>(order.size()) < n; k++)
    {
        int hi = std::min(jac[k], n) - 1;
        int lo = jac[k - 1];
        for (int idx = hi; idx >= lo; idx--)
            order.push_back(idx);
    }
    return order;
}

int PmergeMe::lowerBoundVec(const std::vector<int>& v, int val, int hi)
{
    int lo = 0;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int PmergeMe::lowerBoundDeq(const std::deque<int>& d, int val, int hi)
{
    int lo = 0;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (d[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

void PmergeMe::fjVec(std::vector<int>& v)
{
    int n = static_cast<int>(v.size());
    if (n <= 1)
        return;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? v[n - 1] : 0;
    int pairCnt = n / 2;

    std::vector<std::pair<int,int> > pairs;
    pairs.reserve(pairCnt);
    for (int i = 0; i < pairCnt; ++i)
    {
        int a = v[2 * i], b = v[2 * i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::vector<int> largers;
    largers.reserve(pairCnt);
    for (int i = 0; i < pairCnt; ++i)
        largers.push_back(pairs[i].first);

    fjVec(largers);

    std::stable_sort(pairs.begin(), pairs.end());

    std::vector<int> result;
    result.reserve(n);
    result.push_back(pairs[0].second);
    for (int i = 0; i < pairCnt; i++)
        result.push_back(pairs[i].first);

    std::vector<int> largePos(pairCnt);
    for (int i = 0; i < pairCnt; i++)
        largePos[i] = i + 1;

    std::vector<int> pend;
    pend.reserve(pairCnt);
    for (int i = 1; i < pairCnt; i++)
        pend.push_back(pairs[i].second);
    if (hasStraggler)
        pend.push_back(straggler);
    int pendSz = static_cast<int>(pend.size());
    if (pendSz == 0)
    {
        v = result;
        return;
    }

    std::vector<int> order = buildInsertOrder(pendSz);
    for (int oi = 0; oi < pendSz; oi++)
    {
        int idx = order[oi];
        int val = pend[idx];
        int bound;
        if (!hasStraggler || idx < pendSz - 1)
            bound = largePos[idx + 1];
        else
            bound = static_cast<int>(result.size());
        int pos = lowerBoundVec(result, val, bound);
        result.insert(result.begin() + pos, val);
        for (int j = 0; j < pairCnt; j++)
        {
            if (largePos[j] >= pos)
                largePos[j]++;
        }
    }
    v = result;
}

void PmergeMe::fjDeq(std::deque<int>& d)
{
    int n = static_cast<int>(d.size());
    if (n <= 1) return;
    bool hasStraggler = (n % 2 != 0);
    int  straggler    = hasStraggler ? d[n - 1] : 0;
    int  pairCnt      = n / 2;

    std::deque<std::pair<int,int> > pairs;
    for (int i = 0; i < pairCnt; i++)
    {
        int a = d[2*i], b = d[2*i+1];
        if (a < b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::deque<int> largers;
    for (int i = 0; i < pairCnt; i++)
        largers.push_back(pairs[i].first);

    fjDeq(largers);

    std::vector<std::pair<int,int> > pairsVec(pairs.begin(), pairs.end());
    std::stable_sort(pairsVec.begin(), pairsVec.end());
    pairs.assign(pairsVec.begin(), pairsVec.end());

    std::deque<int> result;
    result.push_back(pairs[0].second);
    for (int i = 0; i < pairCnt; i++)
        result.push_back(pairs[i].first);

    std::vector<int> largePos(pairCnt);
    for (int i = 0; i < pairCnt; i++)
        largePos[i] = i + 1;

    std::deque<int> pend;
    for (int i = 1; i < pairCnt; i++)
        pend.push_back(pairs[i].second);
    if (hasStraggler)
        pend.push_back(straggler);
    int pendSz = static_cast<int>(pend.size());
    if (pendSz == 0)
    {
        d = result;
        return;
    }

    std::vector<int> order = buildInsertOrder(pendSz);
    for (int oi = 0; oi < pendSz; oi++)
    {
        int idx = order[oi];
        int val = pend[idx];
        int bound;
        if (!hasStraggler || idx < pendSz - 1)
            bound = largePos[idx + 1];
        else
            bound = static_cast<int>(result.size());
        int pos = lowerBoundDeq(result, val, bound);
        result.insert(result.begin() + pos, val);
        for (int j = 0; j < pairCnt; j++)
            if (largePos[j] >= pos)
                largePos[j]++;
    }
    d = result;
}

void PmergeMe::run(int argc, char **argv)
{
    parseInput(argc, argv);
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << "\n";
    std::clock_t t0 = std::clock();
    {
        std::vector<int> tmp(_vec);
        fjVec(tmp);
        _vec = tmp;
    }
    std::clock_t t1 = std::clock();
    std::clock_t t2 = std::clock();
    {
        std::deque<int> tmp(_deq);
        fjDeq(tmp);
        _deq = tmp;
    }
    std::clock_t t3 = std::clock();
    double usVec = static_cast<double>(t1 - t0) / CLOCKS_PER_SEC * 1e6;
    double usDeq = static_cast<double>(t3 - t2) / CLOCKS_PER_SEC * 1e6;
    std::cout << "After:";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << "\n";
    std::cout << "Time to process a range of " << _vec.size()
        << " elements with std::vector : " << usVec << " us\n";
    std::cout << "Time to process a range of " << _deq.size()
        << " elements with std::deque  : " << usDeq << " us\n";
}
