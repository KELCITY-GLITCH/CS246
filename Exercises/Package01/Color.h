#ifndef COLOR_H
#define COLOR_H

namespace dsw
{
    class Color
    {
        public:
        int red;
        int blue;
        int green;

        Color() : red(0), blue(0), green(0) {}
        Color(const Color& obj) : red (obj.red), blue(obj.blue), green(obj.green) {}

        Color& operator= (const Color& rhs)
        {
            if (this != &rhs)
            {
                red = rhs.red;
                blue = rhs.blue;
                green = rhs.green;
            }
            return *this;
        }

        ~Color() {}
    };
}

#endif 