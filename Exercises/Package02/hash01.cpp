#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

size_t hash(char key)
{
    key = tolower(key);

    if(key >= 'a' && key <= 'z')
    {
        return key - 'a';
    }

    return 26;
}

bool ContainsAll(fstream& obj)
{
    if(!obj.is_open())
    {
        return false;
    }

    bool letters[26];

    for(size_t i = 0; i < 26; i += 1)
    {
        letters[i] = false;
    }

    char ch;

    while(obj.get(ch))
    {
        size_t index = ::hash(ch);

        if(index < 26)
        {
            letters[index] = true;
        }
    }

    for(size_t i = 0; i < 26; i += 1)
    {
        if(letters[i] == false)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    fstream file;
    string filename;

    cout << "Enter file name: ";
    cin >> filename;

    file.open(filename, ios::in);

    cout << ContainsAll(file) << endl;

    file.close();

    return 0;
}