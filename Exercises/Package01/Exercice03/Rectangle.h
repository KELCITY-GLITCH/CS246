#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Measurable.h"
#include <string>
#include <sstream>
#include <iomanip>

namespace dsw
{
    class Rectangle : public Measurable
    {
        private:
        double quantities[2];

        public:
        Rectangle()
        {
            quantities[0] = 1;
            quantities[1] = 1;
        }

        Rectangle(const Rectangle& obj)
        {
            quantities[0] = obj.quantities[0];
            quantities[1] = obj.quantities[1];
        }

        Rectangle& operator=(const Rectangle& rhs)
        {
            if (this != &rhs)
            {
                quantities[0]=rhs.quantities[0];
                quantities[1]=rhs.quantities[1];
            }
            return *this;
        }

        virtual ~Rectangle() {}

        double width() const {return quantities[0]; }
        double length() const {return quantities[1]; }

        void width(double d)
        {
            if (d > 0 && d <= quantities[1])
            quantities[0] = d;
        }

        void length(double d)
        {
            if (d > 0 && d >= quantities[0])
            quantities[1]= d;
        }

        double perimeter() const override {return 2 * (quantities[0] + quantities[1]); }
        double area() const override { return quantities[0] * quantities[1]; }

        std::string toString() const override
        {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1)
                << "[" << quantities[0] << ","<< quantities[1] << "]";
                return oss.str();
        }

    };
}

#endif