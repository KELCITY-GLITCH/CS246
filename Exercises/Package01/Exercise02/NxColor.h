#ifndef NXCOLOR_H
#define NXCOLOR_H

namespace dsw
{
    class NxColor
    {
        private:
        int red;
        int blue;
        int green;

        public: 
        NxColor() : red(0), blue(0), green(0) {}

        NxColor(const NxColor& obj) : red(obj.red), blue(obj.blue), green(obj.green) {}

        NxColor& operator= (const NxColor& rhs)
        {
            if (this != &rhs)
            {
                red = rhs.red;
                blue = rhs.blue;
                green = rhs.green;
            }
            return *this;
        }

        ~NxColor() {}

        int getRed() const {return red;}
        int getBlue() const {return blue;}
        int getGreen() const {return green;}

        void setRed(int r)
        {
            if (r >= 0 && r <= 255)
            {
                red = r;
            }
        }

        void setBlue(int b)
        {
            if (b >= 0 && b <= 255)
            {
                blue = b;
            }
        }

        void setGreen(int g)
        {
            if (g >= 0 && g <= 255)
            {
                green = g;
            }
        }
    };
}

#endif