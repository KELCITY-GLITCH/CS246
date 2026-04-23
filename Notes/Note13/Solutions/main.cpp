#include <cstdlib>
#include <ctime>
#include "Sorting.h"

int main()
{
    size_t size;

    std::cout << "Enter the size of the arrays: ";
    std::cin >> size;

    dsn::Array<int> a(size), b, c;

    for(int i = 0;i < a.size();i += 1)
    {
        a[i] = rand() % 89 + 10; 
    }
    b = a;
    c = a;

    std::cout << "Original Array:\n" << a << "\n";
    
    std::cout << "\nBubble Sort Run\n";
    dsn::Buble(a);
    
    std::cout << "\nInsertion Sort Run\n";
    dsn::Insertion(b);

    std::cout << "\nSelection Sort Run\n";
    dsn::Selection(c);

    return 0;
}