#ifndef UTIL_H
#define UTIL_H

namespace ds
{
    size_t Fib(size_t n)
    {
        if(n == 0)
        {
            return 0;
        }
        else if(n == 1)
        {
            return 1;
        }
        else
        {
            return Fib(n-1) + Fib(n-2);
        }
    }

    size_t FiB(size_t n)
    {
        size_t fibm = 0, fibn = 1;

        if(n <= 1)
        {
            return n;
        }

        for(size_t i = 2;i <= n;i += 1)
        {
            fibn = fibm + fibn;
            fibm = fibn - fibm;
        }
        return fibn;
    }
}

#endif //UTIL_H