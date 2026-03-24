#ifndef NXCONTACT_H
#define NXCONTACT_H

#include <string>
#include <cctype>
#include "NxName.h"

namespace dsw
{
    class NxContact
    {
        private:
        NxName      name;
        std::string number;

        public:
        NxContact() : number("1111111111") {}

        NxContact(const NxContact& obj) : name(obj.name), number(obj.number) {}

        NxContact& operator=(const NxContact& rhs)
        {
            if (this != &rhs)
            {
                name = rhs.name;
                number = rhs.number;
            }
            return *this;
        }

        ~NxContact() {}

        NxName      getName() const {return name;}
        std::string getNumber () const {return number;}

        void setName(NxName n) {name = n;}

        void setNumber(std::string num)
        {
            if (num.size() == 10)
            {
                for (char c : num)
                {
                    if (!std::isdigit((unsigned char)c)) return;
                }
                number = num;
            }
        }
    };
}

#endif