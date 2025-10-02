#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;

        void mergeInsertSortVec(std::vector<int>& v);
        void mergeInsertSortDeq(std::deque<int>& d);
        void mergeVec(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result);
        void mergeDeq(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result);
        void insertionSortVec(std::vector<int>& v, int left, int right);
        void insertionSortDeq(std::deque<int>& d, int left, int right);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void fillContainers(char** input, int size);
        void sortAndDisplay();
};