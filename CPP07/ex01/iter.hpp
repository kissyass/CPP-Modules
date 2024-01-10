#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename TF>
void iter(T *arr, int len, TF f)
{
    int i;

    i = -1;
    while (++i < len)
        f(arr[i]);
}

#endif