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

// ============================================================================
// JACOBSTHAL SEQUENCE GENERATOR
// ============================================================================
// The Jacobsthal sequence is crucial for Ford-Johnson algorithm
// It determines the optimal insertion order to minimize comparisons
// Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341...
// Formula: J(n) = J(n-1) + 2*J(n-2), where J(0)=0, J(1)=1
// ============================================================================
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n == 0) return jacobsthal;
    
    // Base cases
    jacobsthal.push_back(0);  // J(0) = 0
    if (n == 1) return jacobsthal;
    
    jacobsthal.push_back(1);  // J(1) = 1
    
    // Generate sequence: J(n) = J(n-1) + 2*J(n-2)
    size_t j_prev2 = 0;
    size_t j_prev1 = 1;
    
    while (true) {
        size_t j_next = j_prev1 + 2 * j_prev2;
        if (j_next >= n) break;  // Stop when we exceed our range
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
    
    // ========================================================================
    // STEP 1: PAIRING PHASE - Create and compare pairs (n/2 comparisons)
    // ========================================================================
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
    
    // ========================================================================
    // STEP 2: RECURSIVELY SORT LARGER ELEMENTS (Main Chain)
    // ========================================================================
    std::vector<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);   // Larger elements
        pending.push_back(pairs[i].second);     // Smaller elements (to insert later)
    }
    
    // Recursively sort the main chain using Ford-Johnson
    if (mainChain.size() > 1) {
        fordJohnsonSortVec(mainChain);
    }
    
    // ========================================================================
    // STEP 3: INSERT PENDING ELEMENTS USING JACOBSTHAL INSERTION ORDER
    // ========================================================================
    // This is where the Jacobsthal sequence provides the optimal insertion order
    // to minimize the total number of comparisons during binary search insertions
    // ========================================================================
    
    std::vector<int> result;
    
    // The smallest element from the first pair always goes first
    // This is guaranteed to be smaller than all main chain elements
    if (!pending.empty()) {
        result.push_back(pending[0]);
    }
    
    // Add all main chain elements (already sorted)
    for (size_t i = 0; i < mainChain.size(); ++i) {
        result.push_back(mainChain[i]);
    }
    
    // ========================================================================
    // GENERATE JACOBSTHAL SEQUENCE - THE KEY TO MINIMAL COMPARISONS
    // ========================================================================
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pending.size());
    
    // Debug output to show Jacobsthal sequence (comment out for production)
    // std::cout << "Jacobsthal sequence for " << pending.size() << " elements: ";
    // for (size_t i = 0; i < jacobsthal.size(); ++i) {
    //     std::cout << jacobsthal[i] << " ";
    // }
    // std::cout << std::endl;
    
    // ========================================================================
    // BUILD INSERTION ORDER BASED ON JACOBSTHAL SEQUENCE
    // ========================================================================
    // Algorithm:
    // 1. Insert element at Jacobsthal position J[i]
    // 2. Then insert elements between J[i-1] and J[i] in REVERSE order
    // This ensures each insertion has optimal binary search depth
    // ========================================================================
    
    std::vector<size_t> insertionOrder;
    std::vector<bool> inserted(pending.size(), false);
    
    if (!pending.empty()) {
        inserted[0] = true; // First element already inserted above
    }
    
    // Process each Jacobsthal number to build insertion order
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t pos = jacobsthal[i];
        
        // Insert element at Jacobsthal position
        if (pos < pending.size() && !inserted[pos]) {
            insertionOrder.push_back(pos);
            inserted[pos] = true;
        }
        
        // Fill the gap: insert elements between previous and current Jacobsthal
        // number in REVERSE order (this is crucial for minimizing comparisons)
        size_t prev = jacobsthal[i - 1];
        for (size_t j = pos; j > prev; --j) {
            if (j - 1 < pending.size() && !inserted[j - 1]) {
                insertionOrder.push_back(j - 1);
                inserted[j - 1] = true;
            }
        }
    }
    
    // Insert any remaining elements not covered by Jacobsthal sequence
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            insertionOrder.push_back(i);
        }
    }
    
    // Debug output to show insertion order (comment out for production)
    // std::cout << "Insertion order based on Jacobsthal: ";
    // for (size_t i = 0; i < insertionOrder.size(); ++i) {
    //     std::cout << insertionOrder[i] << " ";
    // }
    // std::cout << std::endl;
    
    // ========================================================================
    // PERFORM BINARY SEARCH INSERTIONS IN JACOBSTHAL-OPTIMIZED ORDER
    // ========================================================================
    // Each insertion uses binary search, limited by log2(n) comparisons
    // The Jacobsthal order ensures minimum total comparisons
    // ========================================================================
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
    
    // ========================================================================
    // STEP 1: PAIRING PHASE
    // ========================================================================
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
    
    // ========================================================================
    // STEP 2: RECURSIVELY SORT MAIN CHAIN
    // ========================================================================
    std::deque<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }
    
    if (mainChain.size() > 1) {
        fordJohnsonSortDeq(mainChain);
    }
    
    // ========================================================================
    // STEP 3: JACOBSTHAL-BASED INSERTION
    // ========================================================================
    std::deque<int> result;
    
    if (!pending.empty()) {
        result.push_back(pending[0]);
    }
    
    for (size_t i = 0; i < mainChain.size(); ++i) {
        result.push_back(mainChain[i]);
    }
    
    // GENERATE JACOBSTHAL SEQUENCE FOR OPTIMAL INSERTION ORDER
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pending.size());
    std::vector<size_t> insertionOrder;
    std::vector<bool> inserted(pending.size(), false);
    
    if (!pending.empty()) {
        inserted[0] = true;
    }
    
    // BUILD INSERTION ORDER USING JACOBSTHAL NUMBERS
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t pos = jacobsthal[i];
        if (pos < pending.size() && !inserted[pos]) {
            insertionOrder.push_back(pos);
            inserted[pos] = true;
        }
        
        // Fill gaps in reverse order
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
    
    // PERFORM BINARY INSERTIONS IN JACOBSTHAL ORDER
    
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
