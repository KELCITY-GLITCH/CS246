#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Node.h"

namespace dsw 
{
    template <class T>
    class Stack 
    {
        private:
        Node<T>* front;

        public:
        Stack() : front(nullptr) {}

        Stack(const Stack<T>& obj)
        {
            front = clone(obj.front);
        }

        Stack<T>& operator=(const Stack<T>& rhs)
        {
            if(this != &rhs)
            {
                clear(front);
                front = clone(rhs.front);
            }
            return *this;
        }

        ~Stack() 
        {
            clear(front);
            front = nullptr;
        }

        void push(const T& obj)
        {
            Node<T>* t = new Node<T>(obj);

            if(front != nullptr)
            {
                t->next() = front;
                t->next()->prev() = t;
            }
            front = t;
        }

        void pop() 
        {
            if(front != nullptr)
            {
                Node<T>* t = front;
                front = front->next();

                if(front != nullptr) {front->prev() = nullptr;}
                delete t;
                t = nullptr;
            }
        }

        bool empty() const {return front == nullptr;}

        const T& top() const 
        {
            if(front != nullptr) {return front->data();}
            throw std::out_of_range("empty stack");
        }
    };
}

#endif
