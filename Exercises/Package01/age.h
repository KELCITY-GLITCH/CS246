#ifndef Age_H
#define Age_H

namespace dsw
{
   class Age
   {

    public:

    int count;

    Age()
    {
        count = 1;
    }

    Age(const Age& A)
    {
        count = A.count;
    }

    Age& operator=(const Age& A)
    {
        if(this != &A )
        {
            count =A.count;
        }
        return *this;
    }
    ~Age(){}



   };



}

#endif