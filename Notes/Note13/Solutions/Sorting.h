#ifndef SORTING_H
#define SORTING_H

#include "Array.h"

namespace dsn 
{
    template <typename T>
    void Buble(Array<T>& data) 
    {
        for(size_t i = 0;i < data.size();i += 1)
        {
            for(size_t j = 0;j < data.size() - 1 - i;j += 1)
            {
                if(data[j] > data[j+1])
                {
                    T t = data[j];
                    data[j] = data[j+1];
                    data[j+1] = t;
                }
            }
            std::cout << data << "\n";
        }
    }

    template <typename T>
    void Insertion(Array<T>& data) 
    {
        for(size_t i = 1;i < data.size();i += 1)
        {
            int j = i - 1;
            T k = data[i];

            while(j >= 0 && data[j] > k)
            {
                data[j+1] = data[j];
                j -= 1;
            }
            data[j+1] = k;
            std::cout << data << "\n";
        }
    }

    template <typename T>
    void Selection(Array<T>& data) 
    {
        for(size_t i = 0;i < data.size();i += 1)
        {
            size_t m = i;
            for(size_t j = i + 1;j < data.size();j += 1)
            {
                if(data[m] > data[j])
                {
                    m = j;
                }
            }

            if(m != i)
            {
                T t = data[i];
                data[i] = data[m];
                data[m] = t;
            } 
            std::cout << data << "\n";
        }
    }
}

#endif