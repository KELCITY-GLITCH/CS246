#ifndef NXSQUARE_H
#define NXSQUARE_H

namespace dsw
{
    class NxSquare
    {
        private:
        double side;

        public:
        NxSquare() : side(1) {}

        NxSquare(const NxSquare& obj) : side(obj.side) {}

        NxSquare& operator=(const NxSquare& rhs)
        {
            if (this != &rhs)
            {
                side = rhs.side;
            }
            return *this;
        }

        ~NxSquare() {}

        double getSide() const { return side; }

        void setSide(double s)
        {
            if (s > 0)
            {
                side = s;
            }
        }
    };
}

#endif
