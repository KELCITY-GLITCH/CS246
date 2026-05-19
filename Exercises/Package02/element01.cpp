#include <iostream>
#include <string>
#include "Object.h"
#include "Stack.h"

using namespace std;
using namespace dsw;

string RCD(string str)
{
    Stack<char> s;

    for(size_t i = 0; i < str.size(); i += 1)
    {
        if(!s.empty() && s.top() == str[i])
        {
            s.pop();
        }
        else
        {
            s.push(str[i]);
        }
    }

    string result = "";

    while(!s.empty())
    {
        result = s.top() + result;
        s.pop();
    }

    return result;
}

int main()
{
    cout << RCD("cabbacdbc") << endl;

    return 0;
}