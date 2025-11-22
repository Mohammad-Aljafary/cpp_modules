#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

void PmergeMe::fillContainers(char** input, int size) {
    for (int i = 1; i < size; ++i) {  // Start from 1 to skip program name
        std::stringstream ss(input[i]);
        int num;
        if (!(ss >> num) || !ss.eof()) {
            throw std::invalid_argument("Invalid input: not a valid integer.");
        }
        if (num < 0) {
            throw std::invalid_argument("Negative numbers are not allowed.");
        }
        vec.push_back(num);
        deq.push_back(num);
    }
}

// Binary search insertion
template<typename Container>
static typename Container::iterator binarySearchInsert(Container& , int value, 
                                                       typename Container::iterator begin,
                                                       typename Container::iterator end) {
    typename Container::iterator left = begin;
    typename Container::iterator right = end;
    
    while (left != right) {
        typename Container::iterator mid = left;
        typename Container::difference_type distance = std::distance(left, right);
        std::advance(mid, distance / 2);
        
        if (*mid < value) {
            left = mid;
            ++left;
        } else {
            right = mid;
        }
    }
    return left;
}

void PmergeMe::insertionSortVec(std::vector<int>& v, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= left && v[j] > key) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}

void PmergeMe::insertionSortDeq(std::deque<int>& d, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = d[i];
        int j = i - 1;
        while (j >= left && d[j] > key) {
            d[j + 1] = d[j];
            --j;
        }
        d[j + 1] = key;
    }
}

void PmergeMe::mergeVec(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result) {
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        result[k++] = left[i++];
    }
    while (j < right.size()) {
        result[k++] = right[j++];
    }
}

void PmergeMe::mergeDeq(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result) {
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        result[k++] = left[i++];
    }
    while (j < right.size()) {
        result[k++] = right[j++];
    }
}

void PmergeMe::mergeInsertSortVec(std::vector<int>& v) {
    if (v.size() <= 1) {
        return;
    }
    
    // Step 1: Group elements into pairs and sort each pair
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (v.size() % 2 != 0);
    int straggler = hasStraggler ? v.back() : 0;
    
    size_t pairCount = v.size() / 2;
    for (size_t i = 0; i < pairCount; ++i) {
        int a = v[i * 2];
        int b = v[i * 2 + 1];
        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    
    // Step 2: Recursively sort the larger elements (first elements of pairs)
    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i) {
        larger.push_back(pairs[i].first);
    }
    
    if (larger.size() > 1) {
        mergeInsertSortVec(larger);
    }
    
    // Step 3: Build the result by inserting smaller elements using binary search
    std::vector<int> result;
    
    // Insert all larger elements first
    for (size_t i = 0; i < larger.size(); ++i) {
        result.push_back(larger[i]);
    }
    
    // Insert smaller elements using Ford-Johnson insertion order (Jacobsthal sequence)
    std::vector<int> smaller;
    for (size_t i = 0; i < pairs.size(); ++i) {
        // Find the position of pairs[i].first in result
        for (size_t j = 0; j < larger.size(); ++j) {
            if (larger[j] == pairs[i].first) {
                smaller.push_back(pairs[i].second);
                break;
            }
        }
    }
    
    // Insert smaller elements using binary search
    for (size_t i = 0; i < smaller.size(); ++i) {
        std::vector<int>::iterator pos = binarySearchInsert(result, smaller[i], 
                                                             result.begin(), result.end());
        result.insert(pos, smaller[i]);
    }
    
    // Insert straggler if exists
    if (hasStraggler) {
        std::vector<int>::iterator pos = binarySearchInsert(result, straggler,
                                                             result.begin(), result.end());
        result.insert(pos, straggler);
    }
    
    v = result;
}

void PmergeMe::mergeInsertSortDeq(std::deque<int>& d) {
    if (d.size() <= 1) {
        return;
    }
    
    // Step 1: Group elements into pairs and sort each pair
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (d.size() % 2 != 0);
    int straggler = hasStraggler ? d.back() : 0;
    
    size_t pairCount = d.size() / 2;
    for (size_t i = 0; i < pairCount; ++i) {
        int a = d[i * 2];
        int b = d[i * 2 + 1];
        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    
    // Step 2: Recursively sort the larger elements
    std::deque<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i) {
        larger.push_back(pairs[i].first);
    }
    
    if (larger.size() > 1) {
        mergeInsertSortDeq(larger);
    }
    
    // Step 3: Build the result
    std::deque<int> result;
    
    for (size_t i = 0; i < larger.size(); ++i) {
        result.push_back(larger[i]);
    }
    
    // Insert smaller elements
    std::vector<int> smaller;
    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = 0; j < larger.size(); ++j) {
            if (larger[j] == pairs[i].first) {
                smaller.push_back(pairs[i].second);
                break;
            }
        }
    }
    
    for (size_t i = 0; i < smaller.size(); ++i) {
        std::deque<int>::iterator pos = binarySearchInsert(result, smaller[i],
                                                            result.begin(), result.end());
        result.insert(pos, smaller[i]);
    }
    
    if (hasStraggler) {
        std::deque<int>::iterator pos = binarySearchInsert(result, straggler,
                                                            result.begin(), result.end());
        result.insert(pos, straggler);
    }
    
    d = result;
}

void PmergeMe::sortAndDisplay() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    clock_t startVec = clock();
    mergeInsertSortVec(vec);
    clock_t endVec = clock();
    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000; // microseconds

    clock_t startDeq = clock();
    mergeInsertSortDeq(deq);
    clock_t endDeq = clock();
    double timeDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000; // microseconds

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}