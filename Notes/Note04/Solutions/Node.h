#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace dsn 
{
    template <class T>
    class Node 
    {
        private:
        T content;
        Node<T>* links[2];

        public:
        Node() 
        {
            content = T();
            links[0] = nullptr;
            links[1] = nullptr;
        }

        Node(const T& obj) : content(obj), links{nullptr,nullptr} {}
        /*
        Node(const T& obj)
        {
            content = obj;
            links[0] = nullptr;
            links[1] = nullptr;
        }
        */

        Node(const Node<T>& obj)
        {
            content = obj.content;
            links[0] = nullptr;
            links[1] = nullptr;
        }

        Node<T>& operator=(const Node<T>& rhs)
        {
            if(this != &rhs)
            {
                content = rhs.content;
            }
            return *this;
        }

        ~Node() {}

        const T& data() const {return content;}

        T& data() {return content;}

        Node<T>*& prev() {return links[0];}

        Node<T>*& next() {return links[1];}

        friend Node<T>* clone(Node<T>* obj)
        {
            if(obj == nullptr) {return nullptr;}
            Node<T>* cp = new Node<T>(obj->content);
            Node<T> *tk = obj, *tr = cp;

            while(tk->links[1] != nullptr)
            {
                tr->links[1] = new Node<T>(tk->links[1]->content);
                tr->links[1]->links[0] = tr;
                tk = tk->links[1];
                tr = tr->links[0];
            }
            return cp;
        }

        friend void clear(Node<T>*& obj)
        {
            Node<T>* t;
            
            while(obj != nullptr)
            {
                t = obj;
                obj = obj->links[1];
                delete t;
                t = nullptr;
            }
        }
        
    };
}



#endif