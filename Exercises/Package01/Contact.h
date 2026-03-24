#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include "Name.h"

namespace dsw
{
    class Contact
    {
        public:
        Name        name;
        std::string number;

        Contact() : number("1111111111") {}

        Contact( const Contact& obj) : name(obj.name), number(obj.number) {}

        Contact& operator= (const Contact& rhs)
        {
            if (this != &rhs)
            {
                name = rhs.name;
                number = rhs.number;
            }
            return *this;
        }
        ~Contact() {}
    };
}

#endif