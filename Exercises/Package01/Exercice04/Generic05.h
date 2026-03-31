#ifndef GENERIC05_H
#define GENERIC05_H

#include "../Array.h"

namespace dsw
{
    template <class T>
    T Range(dsn::Array<T>& arr)
    {
        T min = arr[0];
        T max = arr[0];

        for (size_t i = 1; i < arr.size(); i++)
        {
            if (arr[i] < min) min = arr[i];
            if (arr[i] > max) max = arr[i];
        }

        return max - min;
    }
}

#endif