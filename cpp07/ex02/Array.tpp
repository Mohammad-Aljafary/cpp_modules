#include "Array.hpp"

template <typename T>
Array<T>::Array() : _n(0), _array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n), _array(new T[n]()) {}

template <typename T>
Array<T>::Array(const Array &other) : _n(other._n), _array(new T[other._n]) {
    for (unsigned int i = 0; i < _n; i++) {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] _array;
        _n = other._n;
        _array = new T[_n];
        for (unsigned int i = 0; i < _n; i++) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _n) {
        throw std::out_of_range("Index out of range");
    }
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _n;
}
