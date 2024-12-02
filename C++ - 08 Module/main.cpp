#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <limits>

class Span {
private:
    unsigned int _maxSize;        // Maximum number of integers the Span can store
    std::vector<int> _numbers;    // Container to store the integers

public:
    // Constructor that initializes the Span with a maximum size
    explicit Span(unsigned int N) : _maxSize(N) {}

    // Add a single number to the Span
    void addNumber(int number) {
        if (_numbers.size() >= _maxSize) {
            throw std::overflow_error("Span is already full!");
        }
        _numbers.push_back(number);
    }

    // Add multiple numbers using iterators
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        if (std::distance(begin, end) > static_cast<int>(_maxSize - _numbers.size())) {
            throw std::overflow_error("Not enough space in Span to add all numbers!");
        }
        _numbers.insert(_numbers.end(), begin, 
    }

    // Find the shortest span between numbers
    int shortestSpan() const {
        if (_numbers.size() < 2) {
            throw std::logic_error("Not enough numbers in Span to find a span!");
        }

        std::vector<int> sorted(_numbers);
        std::sort(sorted.begin(), sorted.end());

        int shortest = std::numeric_limits<int>::max();
        for (size_t i = 1; i < sorted.size(); ++i) {
			std::cout << "index [" << i << "] : shortest: "<< shortest << std::endl;
            shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
        }
        return shortest;
    }

    // Find the longest span between numbers
    int longestSpan() const {
        if (_numbers.size() < 2) {
            throw std::logic_error("Not enough numbers in Span to find a span!");
        }

        int minVal = *std::min_element(_numbers.begin(), _numbers.end());
        int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
        return maxVal - minVal;
    }
};

// Test the Span class
int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;  // Output: 2
        std::cout << sp.longestSpan() << std::endl;  // Output: 14

        // Test adding multiple numbers
    //     std::vector<int> largeSet(10000);
    //     std::iota(largeSet.begin(), largeSet.end(), 0);

    //     Span bigSpan(10000);
    //     bigSpan.addNumbers(largeSet.begin(), largeSet.end());
    //     std::cout << bigSpan.shortestSpan() << std::endl;  // Output: 1
    //     std::cout << bigSpan.longestSpan() << std::endl;  // Output: 9999
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
