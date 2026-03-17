#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Node.h"

namespace dsn 
{
    template <class T> class List;
    template <class T> class Iterator;

    template <class T>
    class List
    {
        private:
        Node<T>* head;
        Node<T>* tail;
        size_t length;
        friend class Iterator<T>;

        public:

        List() : head(nullptr), tail(nullptr), length(0) {}

        List(const List<T>& obj)
        {
            head = clone(obj.head);
            tail = head;
            length = obj.length();

            if(head != nullptr)
            {
                while(tail->next() != nullptr) {tail = tail->next();}
            }
        }

        List<T>& operator=(const List<T>& rhs)
        {
            if(this != &rhs)
            {
                clear(head);
                head = clone(rhs.head);
                tail = head;
                length = rhs.length;

                if(head != nullptr)
                {
                    while(tail->next() != nullptr) {tail = tail->next();}
                }
            }
            return *this;
        }

        ~List() 
        {
            clear(head);
            head = nullptr;
            tail = nullptr;
        }

        void prepend(const T& obj)
        {
            //O(1) - simply assignmnts and selection statements
            Node<T>* t = new Node<T>(obj);

            if(head == nullptr)
            {
                head = t;
                tail = t;
            }
            else 
            {
                t->next() = head;
                head->prev() = t;
                head = t;
            }
        }

        void append(const T& obj)
        {
            //O(1)
            Node<T>* t = new Node<T>(obj);

            if(head == nullptr)
            {
                head = t;
                tail = t;
            }
            else 
            {
                t->prev() = tail;
                tail->next() = t;
                tail = t;
            }
        }

        void insert(size_t idx,const T& obj)
        {
            //O(n)
            Node<T>* p = nullptr;

            if(idx <= (length / 2))
            {
                p = head;
                for(size_t i = 0;i < idx;i += 1)
                {
                    p = p->next();
                }
            }
            else if(idx > (length / 2) && idx <= length)
            {
                p = tail;
                for(size_t i = length-idx;i > 0;i -= 1)
                {
                    p = p->prev();
                }
            }

            if((p == nullptr && idx == 0) || p != nullptr)
            {
                Node<T>* t = new Node<T>(obj);

                if(p == nullptr)
                {
                    head = t;
                    tail = t;
                }
                else 
                {
                    t->prev() = p->prev();
                    t->next() = p;                

                    if(t->prev() == nullptr) {head = t;}
                    else {t->prev()->next() = t;}
                    t->next()->prev() = t;
                }
            }
        }
    };

    template <class T>
    class Iterator 
    {
        private:
        List<T>* self;
        Node<T>* node;
        friend class List<T>;

        Iterator(List<T>* l,Node<T>* n) : self(l), node(n) {}

        public:
        Iterator() : self(nullptr), node(nullptr) {}

        Iterator(List<T>& s) : self(&s), node(nullptr) {}

        Iterator(const Iterator<T>& obj) 
        {
            self = obj.self;
            node = obj.node;
        }

        Iterator<T>& operator=(const Iterator<T>& rhs)
        {
            if(this != &rhs)
            {
                self = rhs.self;
                node = rhs.node;
            }
            return *this;
        }

        ~Iterator() 
        {
            self = nullptr;
            node = nullptr;
        }

        void begin() 
        {
            if(self != nullptr) {node = self->head;}
            else {node = nullptr;}
        }

        void end() 
        {
            if(self != nullptr) {node = self->tail;}
            else {node = nullptr;}
        }

        const T& current() const 
        {
            if(node != nullptr) {return node->data();}
            throw std::invalid_argument("iterator not positioned");
        }

        T& current() 
        {
            if(node != nullptr) {return node->data();}
            throw std::invalid_argument("iterator not positioned");
        }

        bool hasNext() const {return (node != nullptr && node->next() != nullptr);}

        bool hasPrevious() const {return (node != nullptr && node->prev() != nullptr);}

        void forward() {if(node != nullptr) {node = node->next();}}

        void backward() {if(node != nullptr) {node = node->prev();}}
    };

}

#endif