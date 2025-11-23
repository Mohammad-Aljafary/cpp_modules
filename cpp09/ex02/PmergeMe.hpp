#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;

        // Ford-Johnson specific helpers
        std::vector<size_t> generateJacobsthalSequence(size_t n);
        
        // Vector implementation
        void fordJohnsonSortVec(std::vector<int>& v);
        size_t binarySearchVec(const std::vector<int>& sorted, int value, size_t end);
        
        // Deque implementation
        void fordJohnsonSortDeq(std::deque<int>& d);
        size_t binarySearchDeq(const std::deque<int>& sorted, int value, size_t end);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void fillContainers(char** input, int size);
        void sortAndDisplay();
};