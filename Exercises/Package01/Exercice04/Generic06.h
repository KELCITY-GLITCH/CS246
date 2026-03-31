#ifndef GENERIC06_H
#define GENERIC06_H

#include "../Object.h"
#include <string>
#include <sstream>

namespace dsw
{
    template <class K, class V>
    class Pair : public Object
    {
        private:
        K key;
        V value;

        public:
        Pair() : key(K()), value(V()) {}

        Pair(const Pair& obj) : key(obj.key), value(obj.value) {}

        Pair& operator=(const Pair& rhs)
        {
            if (this != &rhs)
            {
                key   = rhs.key;
                value = rhs.value;
            }
            return *this;
        }

        virtual ~Pair() {}

        K& mask()    { return key;   }
        V& content() { return value; }

        std::string toString() const override
        {
            std::ostringstream oss;
            oss << "<" << key << "," << value << ">";
            return oss.str();
        }
    };
}

#endif