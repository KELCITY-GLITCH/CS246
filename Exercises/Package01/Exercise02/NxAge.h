#ifndef NXAGE_H
#define NXAGE_H

namespace dsw
{
    class NxAge
    {
        private:
        int count;

        public:
        NxAge() : count(1) {}

        NxAge(const NxAge& obj) : count(obj.count) {}

        NxAge& operator=(const NxAge& rhs)
        {
            if (this != &rhs)
            {
                count = rhs.count;
            }
            return *this;
        }

        ~NxAge() {}

        int getCount() const { return count; }

        void setCount(int c)
        {
            if (c >= 1&& c <= 43800)
            {
                count = c;
            }
        }
    };
}

#endif
