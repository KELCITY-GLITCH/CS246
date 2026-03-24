#ifndef NXCIRCLE_H
#define NXCIRCLE_H

namespace dsw
{
    class NxCircle
    {
        private:
        double radius;
        static const double PI;

        public:
        NxCircle() : radius(1) {}

        NxCircle(const NxCircle& obj) : radius(obj.radius) {}

        NxCircle& operator=(const NxCircle& rhs)
        {
            if (this != &rhs)
            {
                radius = rhs.radius;
            }
            return *this;
        }

        ~NxCircle() {}

        double getRadius() const { return radius; }

        static double getPI() { return PI; }

        void setRadius(double r)
        {
            if (r > 0)
            {
                radius = r;
            }
        }
    };

    const double NxCircle::PI = 3.1415926;
}

#endif
