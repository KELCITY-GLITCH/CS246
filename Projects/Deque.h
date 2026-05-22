#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Node.h"

namespace dsp 
{
    template <class T>
    class Deque 
    {
        private:
        Node<T>* front;
        Node<T>* back;

        public:
        Deque() : front(nullptr), back(nullptr) {}

        Deque(const Deque<T>& obj)
        {
            front = clone(obj.front);
            back = front;

            if(back != nullptr)
            {
                while(back->next() != nullptr)
                {
                    back = back->next();
                }
            }
        }

        Deque<T>& operator=(const Deque<T>& rhs)
        {
            if(this != &rhs)
            {
                clear(front);
                front = clone(rhs.front);
                back = front;

                if(back != nullptr)
                {
                    while(back->next() != nullptr)
                    {
                        back = back->next();
                    }
                }

            }
            return *this;
        }

        ~Deque() 
        {
            clear(front);
            front = nullptr;
            back = nullptr;
        }

        void insertFirst(const T& obj)
        {
            Node<T>* t = new Node<T>(obj);

            if(front != nullptr)
            {
                t->next() = front;
                t->next()->prev() = t;
            }
            else {back = t;}
            front = t;
        }

        void insertLast(const T& obj)
        {
            Node<T>* t = Node<T>(obj);

            if(back != nullptr)
            {
                t->prev() = back;
                t->prev()->next() = t;
            }
            else {front = t;}
            back = t;
        }

        void removeFirst() 
        {
            if(front != nullptr)
            {
                Node<T>* t = front;
                front = front->next();

                if(front != nullptr) {front->prev() = nullptr;}
                else {back = nullptr;}
                delete t;
                t = nullptr;
            }
        }

        void removeLast()
        {
            if(back != nullptr)
            {
                Node<T>* t = back;
                back = back->prev();

                if(back != nullptr) {back->next() = nullptr;}
                else {front = nullptr;}
                delete t;
                t = nullptr;
            }
        }

        bool empty() const {return front == nullptr;}

        const T& first() const 
        {
            if(front != nullptr) {return front->data();}
            throw std::out_of_range("empty deque");
        }

        const T& last() const 
        {
            if(back != nullptr) {return back->data();}
            throw std::out_of_range("empty deque");
        }

    };
}
#endif
