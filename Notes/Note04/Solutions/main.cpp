#include "Node.h"
#include <cstdlib>
#include <ctime>
using namespace dsn;

template <typename T>
T Minimum(Node<T>* obj)
{
    if(obj == nullptr) {return T();}

    T t = obj->data();

    for(Node<T>* i = obj->next();i != nullptr;i = i->next())
    {
        if(t > i->data())
        {
            t = i->data();
        }
    }
    return t;
}

template <typename T>
std::string toString(Node<T>* obj) 
{
    std::stringstream out;

    out << "[";

    for(Node<T>* i = obj;i != nullptr;i = i->next())
    {
        out << i->data();
        if(i->next() != nullptr) {out << ",";}
    }
    out << "]";
    return out.str();
}

int main()
{
    srand(time(nullptr));
    Node<int>* a = new Node<int>(7);
    Node<int>* b = a;

    for(int i = 0;i < 14;i += 1)
    {
        b->next() = new Node<int>(rand() % 100 + 1);
        b->next()->prev() = b;
        b = b->next();
    }

    std::cout << toString(a) << "\n";
    std::cout << Minimum(a) << "\n";
    clear(a);

    return 0;
}