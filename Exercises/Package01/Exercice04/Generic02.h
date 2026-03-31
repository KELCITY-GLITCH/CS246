#ifndef GENERIC02_H
#define GENERIC02_H

#include "../Array.h"

namespace dsw
{
    template <class T>
    bool Contains(dsn::Array<T>& arr, const T& val)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[1] == val)
            return true;
        }
        return false;
    }
}

#endif