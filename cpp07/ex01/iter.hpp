#pragma once

#include <iostream>

template< typename T , typename Func >
void iter(T *array, const size_t length, Func func) {
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}