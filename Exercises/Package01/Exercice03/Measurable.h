#ifndef MEASURABLE_H
#define MEASURABLE_H

#include "../Object.h"

namespace dsw
{
    class Measurable : public Object
    {
        public:
        virtual ~Measurable() {}
        virtual double perimeter() const = 0;
        virtual double area()      const = 0;
    };
}

#endif
