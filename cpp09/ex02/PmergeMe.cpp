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
    for (int i = 1; i < size; ++i) {
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

// Generate Jacobsthal sequence for optimal insertion order
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n == 0) return jacobsthal;
    
    // Generate Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;
    
    jacobsthal.push_back(1);
    
    size_t j_prev2 = 0;
    size_t j_prev1 = 1;
    
    while (true) {
        size_t j_next = j_prev1 + 2 * j_prev2;
        if (j_next >= n) break;
        jacobsthal.push_back(j_next);
        j_prev2 = j_prev1;
        j_prev1 = j_next;
    }
    
    return jacobsthal;
}

// Binary search with comparison count optimization
size_t PmergeMe::binarySearchVec(const std::vector<int>& sorted, int value, size_t end) {
    if (end == 0) return 0;
    
    size_t left = 0;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (sorted[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

size_t PmergeMe::binarySearchDeq(const std::deque<int>& sorted, int value, size_t end) {
    if (end == 0) return 0;
    
    size_t left = 0;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (sorted[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void PmergeMe::fordJohnsonSortVec(std::vector<int>& v) {
    size_t n = v.size();
    if (n <= 1) return;
    
    // Step 1: Create pairs and compare each pair (n/2 comparisons)
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? v[n - 1] : 0;
    
    size_t pairCount = n / 2;
    for (size_t i = 0; i < pairCount; ++i) {
        int a = v[2 * i];
        int b = v[2 * i + 1];
        // One comparison per pair - store larger first, smaller second
        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    
    if (pairs.empty()) {
        return;
    }
    
    // Step 2: Recursively sort the larger elements (main chain)
    std::vector<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }
    
    // Recursively sort the main chain
    if (mainChain.size() > 1) {
        fordJohnsonSortVec(mainChain);
    }
    
    // Step 3: Insert pending elements using Jacobsthal insertion order
    std::vector<int> result;
    
    // The smallest element from the first pair goes first
    if (!pending.empty()) {
        result.push_back(pending[0]);
    }
    
    // Add all main chain elements
    for (size_t i = 0; i < mainChain.size(); ++i) {
        result.push_back(mainChain[i]);
    }
    
    // Generate Jacobsthal sequence for insertion order
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pending.size());
    
    // Create insertion order based on Jacobsthal sequence
    std::vector<size_t> insertionOrder;
    std::vector<bool> inserted(pending.size(), false);
    
    if (!pending.empty()) {
        inserted[0] = true; // First element already inserted
    }
    
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t pos = jacobsthal[i];
        if (pos < pending.size() && !inserted[pos]) {
            insertionOrder.push_back(pos);
            inserted[pos] = true;
        }
        
        // Insert elements between jacobsthal[i-1] and jacobsthal[i] in reverse
        size_t prev = jacobsthal[i - 1];
        for (size_t j = pos; j > prev; --j) {
            if (j - 1 < pending.size() && !inserted[j - 1]) {
                insertionOrder.push_back(j - 1);
                inserted[j - 1] = true;
            }
        }
    }
    
    // Insert remaining elements
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            insertionOrder.push_back(i);
        }
    }
    
    // Perform insertions using binary search
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        size_t idx = insertionOrder[i];
        int value = pending[idx];
        size_t pos = binarySearchVec(result, value, result.size());
        result.insert(result.begin() + pos, value);
    }
    
    // Insert straggler if exists
    if (hasStraggler) {
        size_t pos = binarySearchVec(result, straggler, result.size());
        result.insert(result.begin() + pos, straggler);
    }
    
    v = result;
}

void PmergeMe::fordJohnsonSortDeq(std::deque<int>& d) {
    size_t n = d.size();
    if (n <= 1) return;
    
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? d[n - 1] : 0;
    
    size_t pairCount = n / 2;
    for (size_t i = 0; i < pairCount; ++i) {
        int a = d[2 * i];
        int b = d[2 * i + 1];
        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    
    if (pairs.empty()) {
        return;
    }
    
    std::deque<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }
    
    if (mainChain.size() > 1) {
        fordJohnsonSortDeq(mainChain);
    }
    
    std::deque<int> result;
    
    if (!pending.empty()) {
        result.push_back(pending[0]);
    }
    
    for (size_t i = 0; i < mainChain.size(); ++i) {
        result.push_back(mainChain[i]);
    }
    
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pending.size());
    std::vector<size_t> insertionOrder;
    std::vector<bool> inserted(pending.size(), false);
    
    if (!pending.empty()) {
        inserted[0] = true;
    }
    
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t pos = jacobsthal[i];
        if (pos < pending.size() && !inserted[pos]) {
            insertionOrder.push_back(pos);
            inserted[pos] = true;
        }
        
        size_t prev = jacobsthal[i - 1];
        for (size_t j = pos; j > prev; --j) {
            if (j - 1 < pending.size() && !inserted[j - 1]) {
                insertionOrder.push_back(j - 1);
                inserted[j - 1] = true;
            }
        }
    }
    
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            insertionOrder.push_back(i);
        }
    }
    
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        size_t idx = insertionOrder[i];
        int value = pending[idx];
        size_t pos = binarySearchDeq(result, value, result.size());
        result.insert(result.begin() + pos, value);
    }
    
    if (hasStraggler) {
        size_t pos = binarySearchDeq(result, straggler, result.size());
        result.insert(result.begin() + pos, straggler);
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
    fordJohnsonSortVec(vec);
    clock_t endVec = clock();
    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    clock_t startDeq = clock();
    fordJohnsonSortDeq(deq);
    clock_t endDeq = clock();
    double timeDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
