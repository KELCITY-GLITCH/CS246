#include <iostream>
#include <string>
#include "Object.h"
#include "Array.h"
#include "Map.h"

using namespace std;
using namespace dsw;

string MW(Array<string>& root)
{
    Map<string, int> count;

    for(size_t i = 0; i < root.size(); i += 1)
    {
        string word = root[i];

        if(count.contains(word))
        {
            int oldCount = count.get(word);
            count.put(word, oldCount + 1);
        }
        else
        {
            count.put(word, 1);
        }
    }

    string most = root[0];
    int highest = count.get(root[0]);

    for(size_t i = 1; i < root.size(); i += 1)
    {
        string word = root[i];

        if(count.get(word) > highest)
        {
            highest = count.get(word);
            most = word;
        }
    }

    return most;
}

int main()
{
    Array<string> words = {
        "apple",
        "banana",
        "apple",
        "orange",
        "banana",
        "apple",
        "grape",
        "pear",
        "apple",
        "kiwi"
    };

    cout << MW(words) << endl;

    return 0;
}