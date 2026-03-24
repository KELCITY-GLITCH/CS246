#ifndef NXPERSON_H
#define NXPERSON_H

#include "NxName.h"
#include "NxAge.h"

namespace dsw
{
    class NxPerson
    {
        private:
        NxName name;
        NxAge  age;

        public:
        NxPerson() {}

        NxPerson(const NxPerson& obj) : name(obj.name), age(obj.age) {}

        NxPerson& operator=(const NxPerson& rhs)
        {
            if (this != &rhs)
            {
                name = rhs.name;
                age  = rhs.age;
            }
            return *this;
        }

        ~NxPerson() {}

        NxName getName() const { return name; }
        NxAge  getAge()  const { return age;  }

        void setName(NxName n) { name = n; }
        void setAge(NxAge a)   { age  = a; }
    };
}

#endif
