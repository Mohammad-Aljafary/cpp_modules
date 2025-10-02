#include "PmergeMe.hpp"

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
    for (int i = 0; i < size; ++i) {
        int num = std::atoi(input[i]);
        if (num < 0) {
            throw std::invalid_argument("Negative numbers are not allowed.");
        }
        vec.push_back(num);
        deq.push_back(num);
    }
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
    if (v.size() <= 10) {
        insertionSortVec(v, 0, v.size() - 1);
        return;
    }
    size_t mid = v.size() / 2;
    std::vector<int> left(v.begin(), v.begin() + mid);
    std::vector<int> right(v.begin() + mid, v.end());
    mergeInsertSortVec(left);
    mergeInsertSortVec(right);
    mergeVec(left, right, v);
}

void PmergeMe::mergeInsertSortDeq(std::deque<int>& d) {
    if (d.size() <= 10) {
        insertionSortDeq(d, 0, d.size() - 1);
        return;
    }
    size_t mid = d.size() / 2;
    std::deque<int> left(d.begin(), d.begin() + mid);
    std::deque<int> right(d.begin() + mid, d.end());
    mergeInsertSortDeq(left);
    mergeInsertSortDeq(right);
    mergeDeq(left, right, d);
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