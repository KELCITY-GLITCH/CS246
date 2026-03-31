#ifndef GENERIC03_H
#define GENERIC03_H

#include "../Array.h"

namespace dsw
{
    template <class T>
    bool Sorted(dsn::Array<T>& arr)
    {
        for (size_t i = 0; i + 1< arr.size(); i++)
        {
            if (arr[i] > arr[i + 1])
            return false;
        }
        return true;
    }
}

#endif