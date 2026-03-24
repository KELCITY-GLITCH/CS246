#ifndef NXTEXTBOX_H
#define NXTEXTBOX_H

#include <string>

namespace dsw
{
    class NxTextBox
    {
        private:
        std::string name;
        std::string content;

        public:
        NxTextBox() : name("default"), content("Type text here ...") {}

        NxTextBox(const NxTextBox& obj) : name(obj.name), content(obj.content) {}

        NxTextBox& operator=(const NxTextBox& rhs)
        {
            if (this != &rhs)
            {
                name    = rhs.name;
                content = rhs.content;
            }
            return *this;
        }

        ~NxTextBox() {}

        std::string getName()    const { return name;    }
        std::string getContent() const { return content; }

        void setName(std::string n)
        {
            if (!n.empty())
            {
                name = n;
            }
        }

        void setContent(std::string c)
        {
            if (!c.empty())
            {
                content = c;
            }
        }
    };
}

#endif
