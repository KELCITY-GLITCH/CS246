#ifndef GENERIC01_H
#define GENERIC01_H

#include "../Array.h"

namespace dsw
{
    template <class T>
    int Count(dsn::Array<T>& arr, const T& val)
    {
        int count = 0;
        for (size_t i = 0; i <arr.size(); i++)
        {
            if (arr[i] == val)
            count++;
        }
        return count;
    }
}

#endif 