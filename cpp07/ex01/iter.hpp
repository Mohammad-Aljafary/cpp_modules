#pragma once

#include <iostream>

template< typename T >
void iter(T *array, const size_t length, void (*func)(T &)) {
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}