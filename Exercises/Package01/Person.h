#ifndef PERSON_H
#define PERSON_H

#include "Name.h"
#include "Age.h"

namespace dsw
{
   class Person
   {
        public:
        Name name;
        Age age;

        Person() {}

        Person(const Person& obj)
        {
            name = obj.name;
            age = obj.age;
        }

        Person& operator=(const Person& rhs)
        {
            if (this != &rhs)
            {
                name = rhs.name;
                age = rhs.age;
            }
            return *this;
        }

        ~Person() {}

   };
}

#endif