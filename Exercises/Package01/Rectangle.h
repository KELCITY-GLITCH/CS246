
#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace dsw
{
    class Rectangle
    {
        public:
        double length;
        double width;

        Rectangle() : length(1), width(1){}

        Rectangle(const Rectangle& obj)
        {
            length = obj.length;
            width = obj.width;
        }
        Rectangle& operator=(const Rectangle& rhs)
        {
            if (this != &rhs)
            {
                length = rhs.length;
                width = rhs.width;
            }
            return *this;
        }
        ~Rectangle() {}
    };
}
#endif