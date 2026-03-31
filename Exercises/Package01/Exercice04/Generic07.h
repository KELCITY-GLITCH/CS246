#ifndef GENERIC07_H
#define GENERIC07_H

#include "../Object.h"
#include <string>
#include <sstream>

namespace dsw
{
    template <class T>
    class Item : public Object
    {
        private:
        T content;
        static int count;

        public:
        Item() : content(T()) {}

        Item(const Item& obj) : content(obj.content)
        {
            count++;
        }

        Item& operator=(const Item& rhs)
        {
            if (this != &rhs)
                content = rhs.content;
            return *this;
        }

        virtual ~Item() { count--; }

        const T& object() const { return content; }

        void object(const T& v) { content = v; }

        int amount() const { return count; }

        std::string toString() const override
        {
            std::ostringstream oss;
            oss << content << " (" << count << ")";
            return oss.str();
        }
    };

    template <class T>
    int Item<T>::count = 0;
}

#endif