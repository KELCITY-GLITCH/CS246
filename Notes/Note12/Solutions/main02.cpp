#include <iostream>
#include <cctype> //isalpha(), tolower(), isdigit()
#include "HashMap.h"
#include "Iterator.h"

size_t strings(const std::string& key)
{
    char k = key[0];
    if(isdigit(k)) {return (k - '0');}
    else if(isalpha(k)) {return 10 + (tolower(k) - 'a');}
    return 36;   
}

int main() 
{
    dsn::HashMap<std::string,int> map(strings);
    std::string str, c; 

    std::cout << "Enter a string: ";
    std::getline(std::cin,str);
    std::stringstream in(str);

    while(in >> c)
    {
        map.get(c) += 1;
    }

    dsn::Iterator<dsn::Pair<std::string,int>> it = map.items();

    for(it.start();it.hasNext();it.forward())
    {
        std::cout << it.current().key() << ": ";
        std::cout << it.current().value() << "\n";
    }
    
    return 0;
}