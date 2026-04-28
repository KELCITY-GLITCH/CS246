#include <iostream> 
#include <string>
#include "Node.h"
using namespace dsn;

template <typename T>
void forward(Node<T>* node)
{
    for(Node<T>* t = node;t != nullptr;t = t->next)
    {
        std::cout << t->data << "\n";
    }
}

template <typename T>
void backwards(Node<T>* node)
{
    for(Node<T>* t = node;t != nullptr;t = t->prev)
    {
        std::cout << t->data << "\n";
    }
}

template <typename T>
Node<T>* copy(Node<T>* rt)
{
    if(rt == nullptr) {return nullptr;}
    Node<T>* cp = new Node<T>(rt->data);
    Node<T> *tr = rt, *tc = cp;

    while(tr->next != nullptr)
    {
        tc->next = new Node<T>(tr->next->data);
        tc->next->prev = tc;
        tc = tc->next;
        tr = tr->next;
    }
    return cp;
}

template <typename T>
void destroy(Node<T>*& rt)
{
    Node<T>* t;

    while(rt != nullptr)
    {
        t = rt;
        rt = rt->next;
        delete t;
        t = nullptr;
    }
}

int main()
{
    Node<double>* nodes[3] = {new Node<double>(10.0), new Node<double>(15.0), new Node<double>(100.5)};
    nodes[0]->next = nodes[1];
    nodes[1]->prev = nodes[0];
    nodes[1]->next = nodes[2];
    nodes[2]->prev = nodes[1];
    std::cout << "forward traversal of node[0]\n";
    forward(nodes[0]);
    std::cout << "\nbackwards traversal of node[2]\n";
    backwards(nodes[2]);
    Node<double>* c = copy(nodes[0]);
    std::cout << "\nforward traversal of c\n";
    forward(c);
    destroy(nodes[0]);
    destroy(c);
    return 0;
}