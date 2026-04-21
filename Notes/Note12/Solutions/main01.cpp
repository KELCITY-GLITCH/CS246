#include <iostream>
#include <cctype> //isalpha(), tolower(), isdigit()
#include "HashMap.h"
#include "Iterator.h"

size_t characters(const char& key)
{
    if(isdigit(key)) {return (key - '0');}
    else if(isalpha(key)) {return 10 + (tolower(key) - 'a');}
    return 36;
}

int main() 
{
    dsn::HashMap<char,int> map(characters);
    std::string str; 

    std::cout << "Enter a string: ";
    std::cin >> str;

    for(auto c : str)
    {
        map.get(tolower(c)) += 1;
    }

    dsn::Iterator<dsn::Pair<char,int>> it = map.items();

    for(it.start();it.hasNext();it.forward())
    {
        std::cout << it.current().key() << ": ";
        std::cout << it.current().value() << "\n";
    }
    
    return 0;
}