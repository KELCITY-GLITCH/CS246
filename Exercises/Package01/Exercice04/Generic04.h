#ifndef GENERIC04_H
#define GENERIC04_H

#include "../Object.h"
#include <string>
#include <sstream>

namespace dsw
{
    template <class T>
    class Value : public Object
    {
        private:
        T value;

        Value() {}

        Value& operator=(const Value& rhs)
        {
            if (this != &rhs)
                value = rhs.value;
            return *this;
        }

        public:
        Value(const T& v) : value(v) {}

        Value(const Value& obj) : value(obj.value) {}

        virtual ~Value() {}

        const T& get() const { return value; }

        bool equals(const T& v) const { return value == v; }

        void set(const T& v) { value = v; }

        std::string toString() const override
        {
            std::ostringstream oss;
            oss << "value is " << value;
            return oss.str();
        }
    };
}

#endif