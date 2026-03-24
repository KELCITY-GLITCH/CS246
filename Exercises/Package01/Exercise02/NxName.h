#ifndef NXNAME_H
#define NXNAME_H

#include <string>
#include <cctype>

namespace dsw
{
    class NxName
    {
        private:
        std::string firstName;
        std::string lastName;

        public:
        NxName() : firstName("Jane"), lastName("Doe") {}

        NxName(const NxName& obj) : firstName(obj.firstName), lastName(obj.lastName) {}

        NxName& operator=(const NxName& rhs)
        {
            if (this != &rhs)
            {
                firstName = rhs.firstName;
                lastName  = rhs.lastName;
            }
            return *this;
        }

        ~NxName() {}

        std::string getFirstName() const { return firstName; }
        std::string getLastName()  const { return lastName;  }

        void setFirstName(std::string fn)
        {
            if (!fn.empty())
            {
                for (char c : fn)
                {
                    if (!std::isalpha(c)) return;
                }
                firstName = fn;
            }
        }

        void setLastName(std::string ln)
        {
            if (!ln.empty())
            {
                for (char c : ln)
                {
                    if (!std::isalpha(c)) return;
                }
                lastName = ln;
            }
        }

    };
}

#endif
