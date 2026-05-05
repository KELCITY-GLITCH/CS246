#include "Map.h"
#include "Set.h"
#include "MultiSet.h"
#include <cctype>

int main()
{
    dsn::Map<std::string,size_t> phoneBook;
    std::string name;
    size_t number;
    char ch = 'Y';

    while(ch == 'Y')
    {
        std::cout << "Enter a name: ";
        std::cin >> name;

        std::cout << "Enter a number: ";
        std::cin >> number;

        phoneBook.put(name,number);

        std::cout << "Do you want to enter another contact, enter y: ";
        std::cin >> ch;
        ch = toupper(ch);
    }

    std::cout << "Your phonebook has " << phoneBook.size() << "\n";

    std::cout << "Enter a contact's name: ";
    std::cin >> name;

    if(phoneBook.contains(name))
    {
        size_t num = phoneBook.get(name);
        std::cout << name << "'s phone number is " << num << "\n";
        dsn::Set<size_t> s;

        while(num > 0)
        {
            s.add(num % 10);
            num /= 10;
        }
        std::cout << name << "'s number has " << s.size() << " distinct digits\n"; 
    }
    else 
    {
        std::cout << name << " is not a contact\n";
    }
    return 0;
}