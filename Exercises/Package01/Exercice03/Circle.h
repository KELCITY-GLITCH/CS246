#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Object.h"
#include <string>
#include <sstream>
#include <iomanip>

namespace dsw
{
    class Circle : public Object
    {
        private:
        static const double PI;
        double quantity;

        public:
        Circle() : quantity(1) {}

        Circle(const Circle& obj) : quantity(obj.quantity) {}
        Circle& operator=(const Circle& rhs)
        {
            if(this != &rhs)
            quantity = rhs.quantity;
            return *this;
        }

        virtual ~Circle() {}
        double radius() const { return quantity; }

        void radius(double d)
        {
            if (d > 0)
            quantity = d;
        }

        double circumference() const {return 2 * quantity * PI; }
        double area() const { return quantity * quantity * PI; }

        std::string toString() const override
        {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1) << "(" << quantity << ")";
            return oss.str();
        }

    };

    const double Circle::PI = 3.141592;
}

#endif