#ifndef NAME_H
#define NAME_H
#include <string>

using namespace std;

namespace dsw
{
    class Name
    {
        public:
        string firstName;
        string lastName;

        Name() {firstName = "Jane"; lastName = "Doe";}

        Name(const Name& obj)
        {
            firstName = obj.firstName;
            lastName = obj.lastName;
        }
        Name& operator=(const Name &rhs)
        {
            if (this != &rhs)
            {
                firstName = rhs.firstName;
                lastName = rhs.lastName;
            }
            return *this;
        }
        ~Name() {}

    };
}

#endif 