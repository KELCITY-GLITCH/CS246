#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Node.h"

namespace dsw 
{
    template <class T>
    class Queue 
    {
        private:
        Node<T>* front;
        Node<T>* back;

        public:
        Queue() : front(nullptr), back(nullptr) {}

        Queue(const Queue<T>& obj)
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

        Queue<T>& operator=(const Queue<T>& rhs)
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

        ~Queue() 
        {
            clear(front);
            front = nullptr;
            back = nullptr;
        }

        void enqueue(const T& obj)
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

        void dequeue() 
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

        bool empty() const {return front == nullptr;}

        const T& peek() const 
        {
            if(front != nullptr) {return front->data();}
            throw std::out_of_range("empty deque");
        }
    };
}
#endif
