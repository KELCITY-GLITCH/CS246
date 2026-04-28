#ifndef ADVANCESORTING_H
#define ADVANCESORTING_H

#include <iostream>
#include <cstdlib> // rand()
#include <ctime> 
#include "Array.h"
#include "Object.h"

namespace dsn
{
    template <typename T>
    void Merge(Array<T>& data, size_t p, size_t r, size_t q)
    {
        size_t i = 0;
        size_t n = q - p + 1;
        Array<T> t(n);
        size_t lc = p;
        size_t rc = r + 1;

        //sorting the two subarrays into an auxiliary array
        while(i < n)
        {
            if(rc > q || (lc < r + 1 && data[lc] <= data[rc]))
            {
                t[i] = data[lc];
                lc += 1;
            }
            else 
            {
                t[i] = data[rc];
                rc += 1;
            }
            i += 1;
        }

        //populate array with its content sorted
        //copy auxiliary array to the total subarray
        for(i = p;i <= q;i += 1)
        {
            data[i] = t[i-p];
        }
    }

    template <typename T>
    void MergeSort(Array<T>& data, size_t p, size_t q)
    {
        if(p < q)
        {
            size_t r = (p + q) / 2;
            MergeSort(data,p,r);
            MergeSort(data,r+1,q);
            Merge(data,p,r,q);
            std::cout << "(" << p << "," << r << "," << q << ") = " << data << "\n";
        }
    }

    template <typename T>
    int Partition(Array<T>& data,int p,int q)
    {
        T t = data[q];
        int i = p - 1;

        for(int j = p;j < q;j += 1)
        {
            if(data[j] <= t)
            {
                i += 1;
                T s = data[j];
                data[j] = data[i];
                data[i] = s;
            }
        }

        T s = data[q];
        data[q] = data[i+1];
        data[i+1] = s;
        
        return i + 1;
    }

    template <typename T>
    int RandomizePartition(Array<T>& data,int p,int q)
    {
        int r = rand() % (q - p + 1) + p;
        T s = data[r];
        data[r] = data[q];
        data[q] = s;
        return Partition(data,p,q);
    } 
    
    template <typename T>
    void QuickSort(Array<T>& data,int p,int q)
    {
        if(p < q)
        {
            int r = Partition(data,p,q);
            std::cout << "(" << p << "," << q << "," << r << ") = " << data << "\n";
            QuickSort(data,p,r-1);
            QuickSort(data,r+1,q);
        }
    }

    template <typename T>
    void RandomizeQuickSort(Array<T>& data,int p,int q)
    {
        if(p < q)
        {
            int r = RandomizePartition(data,p,q);
            std::cout << "(" << p << "," << q << "," << r << ") = " << data << "\n";
            RandomizeQuickSort(data,p,r-1);
            RandomizeQuickSort(data,r+1,q);
        }
    }
    
}

#endif
