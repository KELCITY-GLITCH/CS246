#ifndef SQUARE_H
#define SQUARE_H

#include "Regular.h"
#include <string>
#include <sstream>
#include <iomanip>

namespace dsw
{
    class Square : public Regular 
    {
        public:
        Square() : Regular() {}

        Square(const Square& obj) : Regular(obj) {}

        Square& operator=(const Square& rhs)
        {
            if (this != &rhs)
            Regular::operator=(rhs);
            return *this;
        }

        virtual ~Square() {}
         
        int sides() const override { return 4; }
        double area() const override { return length() * length(); }

        std::string toString() const override
        {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1) << "[" << length() << "]";
            return oss.str();
        }
    };
}

#endif