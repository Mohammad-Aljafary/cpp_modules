#pragma once 

#include <iostream>
#include <string>

template <typename T>
class Array {
    private:
        unsigned int _n;
        T *_array;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        ~Array();
        Array &operator=(const Array &other);
        T &operator[](unsigned int index);
        unsigned int size() const;
};

#include "Array.tpp"
