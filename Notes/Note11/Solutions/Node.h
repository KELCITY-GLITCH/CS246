#ifndef NODE_H
#define NODE_H

namespace dsn 
{
    template <class T>
    class Node
    {
        public:
        T data;
        Node<T>* next;
        Node<T>* prev;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    template <typename T>
    Node<T>* clone(Node<T>* rt)
    {
        if(rt == nullptr)
        {
            return nullptr;
        }
        Node<T> *cp = new Node<T>(rt->data);
        Node<T>* tr = rt;
        Node<T>* tc = cp;
        
        while(tr->next != nullptr)
        {
            tc->next = new Node<T>(tr->next->data);
            tc->next->prev = tc;
            tr = tr->next;
            tc = tc->next;
        }
        return cp;
    }

    template <typename T>
    void destroy(Node<T>*& rt)
    {
        Node<T> *t ;
        while(rt != nullptr)
        {
            t = rt;
            rt = rt->next;
            delete t;
            t = nullptr;
        }
    }
}

#endif