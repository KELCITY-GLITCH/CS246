#ifndef NXRECTANGLE_H
#define NXRECTANGLE_H

namespace dsw
{
    class NxRectangle
    {
        private:
        double length;
        double width;

        public:
        NxRectangle() : length(1), width(1) {}

        NxRectangle(const NxRectangle& obj) : length(obj.length), width(obj.width) {}

        NxRectangle& operator=(const NxRectangle& rhs)
        {
            if (this != &rhs)
            {
                length = rhs.length;
                width  = rhs.width;
            }
            return *this;
        }

        ~NxRectangle() {}

        double getLength() const { return length; }
        double getWidth()  const { return width;  }

        void setLength(double l)
        {
            if (l > 0)
            {
                length = l;
            }
        }

        void setWidth(double w)
        {
            if (w > 0)
            {
                width = w;
            }
        }
    };
}

#endif
