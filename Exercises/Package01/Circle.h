#ifndef CIRCLE_H
#define CIRCLE_H

namespace dsw
{
    class Circle
    {
        public:
        double radius;
        static const double PI;

        Circle() : radius(1) {}

        Circle(const Circle& obj) : radius(obj.radius) {}

        Circle& operator=(const Circle& rhs)
        {
            if(this != &rhs)
            {
                radius = rhs.radius;
            }
            return *this;
        }
        ~Circle() {}

    };

    const double Circle::PI = 3.1415926;
}
#endif

