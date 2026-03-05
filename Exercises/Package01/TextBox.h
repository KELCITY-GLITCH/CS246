#ifndef TEXTBOX_H
#define TEXTBOX_H
using namespace std;

#include <string> 

namespace dsw{
class TextBox {
    public:
        TextBox(): name("default"), content("Type text here ...") {}

        TextBox(const TextBox& obj)
        {
            name = obj.name;
            content = obj.content;
        }
            string name;
            string content;

        TextBox& operator=(const TextBox &rhs)
        {
            if (this != &rhs)
            {
                name = rhs.name;
                content = rhs.content;
            }
            return *this;
        }

        ~TextBox(){}
};
 }
#endif
