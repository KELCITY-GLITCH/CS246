#ifndef REGULAR_H
#define REGULAR_H

#include "Measurable.h"

namespace dsw
{
    class Regular : public Measurable
    {
        private:
        double quantity;

        public:
        Regular() : quantity(1) {}
        Regular(const Regular& obj) : quantity(obj.quantity) {}
        
        Regular& operator = (const Regular& rhs)
        {
            if (this != &rhs)
            quantity = rhs.quantity;
            return *this;
        }

    virtual ~Regular() {} 

    double length() const {return quantity;}

    void length(double d)
    {
        if (d > 0)
        quantity = d;
    }

    virtual int sides() const = 0;
    double perimeter() const override {return quantity * sides(); }

        
    };

}

#endif