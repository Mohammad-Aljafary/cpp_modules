#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() {
            return std::stack<T>::c.begin();
        }

        iterator end() {
            return std::stack<T>::c.end();
        }
};
