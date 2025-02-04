#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <iomanip>
# include <utility>
# include <string>
# include <vector>
# include <exception>
# include <deque>
# include <algorithm>
# include <iomanip>
# include <ctime>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::swap;

template <typename T>
class PmergeMe {
private:
    T arr;
    double arrTimeTakes;

public:
    PmergeMe(T arr) : arr(arr) {
        std::clock_t start = std::clock();
        fordJohnsonSort(this->arr);
        std::clock_t end = std::clock();
        arrTimeTakes = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }

    double timeTakes() const { return arrTimeTakes; }
    T& getArr() { return arr; }

private:
    void fordJohnsonSort(T& arr) {
        if (arr.size() <= 1) return;

        for (size_t i = 0; i < arr.size() - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }

        T larger, smaller;
        for (size_t i = 1; i < arr.size(); i += 2) {
            larger.push_back(arr[i]);
        }
        for (size_t i = 0; i < arr.size(); i += 2) {
            smaller.push_back(arr[i]);
        }

        fordJohnsonSort(larger);

        T jacob = generateJacobsthal(smaller.size());
        size_t prev = 0;
        for (typename T::iterator j = jacob.begin(); j != jacob.end(); ++j) {
            for (size_t k = *j; k > prev; --k) {
                size_t idx = k - 1;
                if (idx >= smaller.size()) continue;
                typename T::iterator it = std::lower_bound(larger.begin(), larger.end(), smaller[idx]);
                larger.insert(it, smaller[idx]);
            }
            prev = *j;
        }

        for (size_t k = prev + 1; k <= smaller.size(); ++k) {
            size_t idx = k - 1;
            typename T::iterator it = std::lower_bound(larger.begin(), larger.end(), smaller[idx]);
            larger.insert(it, smaller[idx]);
        }

        arr = larger;
    }

    T generateJacobsthal(int limit) {
        T seq;
        if (limit == 0) return seq;
        seq.push_back(0);
        seq.push_back(1);
        while (seq.back() < limit) {
            size_t next = seq.back() + 2 * *(seq.rbegin() + 1);
            seq.push_back(next);
        }
        seq.back() = limit;
        return T(seq.begin() + 2, seq.end());
    }
};

#endif // PMERGEME_HPP