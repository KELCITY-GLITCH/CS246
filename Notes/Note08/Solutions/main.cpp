#include <iostream>
#include <string>
#include <cctype>
#include "Map.h"

std::string getWord(std::string& str)
{
    int i = 0;
    std::string result = "";

    while(i < str.size() && !isalpha(str[i])) {i += 1;}

    while(i < str.size() && isalpha(str[i]))
    {
        result += tolower(str[i]);
        i += 1;
    }
    str = str.substr(i);
    return result;
}

int main()
{
    dsn::Map<std::string,int> a;
    std::string sentence, word;
    
    std::cout << "Enter a sentence: ";
    std::getline(std::cin,sentence);    

    while(true) 
    {
        word = getWord(sentence);

        if(word.empty()) {break;}
        a.get(word) += 1;
    } 

    dsn::Iterator<dsn::Pair<std::string,int>> it = a.items();
    
    it.start();

    while(it.hasNext())
    {
        std::cout << it.current().key() << " (" << it.current().value() << ")\n";
        it.forward();
    }

    return 0;
}