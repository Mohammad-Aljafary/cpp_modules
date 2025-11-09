#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

        iterator begin() {
            return std::stack<T>::c.begin();
        }

        iterator end() {
            return std::stack<T>::c.end();
        }

        reverse_iterator rbegin() {
            return std::stack<T>::c.rbegin();
        }

        reverse_iterator rend() {
            return std::stack<T>::c.rend();
        }

        iterator const begin() const {
            return std::stack<T>::c.begin();
        }

        iterator const end() const {
            return std::stack<T>::c.end();
        }

        reverse_iterator const rbegin() const {
            return std::stack<T>::c.rbegin();
        }

        reverse_iterator const rend() const {
            return std::stack<T>::c.rend();
        }

};
