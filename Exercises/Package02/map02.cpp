#include <iostream>
#include <string>
#include "Object.h"
#include "Array.h"
#include "Map.h"

using namespace std;
using namespace dsw;

string DS(string str)
{
    Map<string, string> code;

    code.put("1", "a");
    code.put("2", "b");
    code.put("3", "c");
    code.put("4", "d");
    code.put("5", "e");
    code.put("6", "f");
    code.put("7", "g");
    code.put("8", "h");
    code.put("9", "i");
    code.put("10#", "j");
    code.put("11#", "k");
    code.put("12#", "l");
    code.put("13#", "m");
    code.put("14#", "n");
    code.put("15#", "o");
    code.put("16#", "p");
    code.put("17#", "q");
    code.put("18#", "r");
    code.put("19#", "s");
    code.put("20#", "t");
    code.put("21#", "u");
    code.put("22#", "v");
    code.put("23#", "w");
    code.put("24#", "x");
    code.put("25#", "y");
    code.put("26#", "z");

    string result = "";

    for(size_t i = 0; i < str.size(); i += 1)
    {
        string key = "";

        if(i + 2 < str.size() && str[i + 2] == '#')
        {
            key += str[i];
            key += str[i + 1];
            key += str[i + 2];

            result += code.get(key);

            i += 2;
        }
        else
        {
            key += str[i];

            result += code.get(key);
        }
    }

    return result;
}

int main()
{
    cout << DS("10#12") << endl;
    cout << DS("11#920#5") << endl;

    return 0;
}