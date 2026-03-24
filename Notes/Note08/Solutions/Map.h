#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Node.h"
#include "Pair.h"
#include "Iterator.h"

namespace dsn 
{
    template <class K,class V>
    class Map 
    {
        private:
        Node<Pair<K,V>>* head;
        size_t length;

        public:
        Map() : head(nullptr), length(0) {}

        Map(const Map<K,V>& obj)
        {
            head = clone(obj.head);
            length = obj.length;
        }

        Map<K,V>& operator=(const Map<K,V>& rhs)
        {
            if(this != &rhs)
            {
                clear(head);
                head = clone(rhs.head);
                length = rhs.length;
            }
            return *this;
        }

        ~Map() 
        {
            clear(head);
            head = nullptr;
        }

        bool empty() const {return head == nullptr;}

        size_t size() const {return length;}

        void put(const K& key,const V& value)
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            if(t == nullptr)
            {
                t = new Node<Pair<K,V>>(Pair(key,value));

                if(head != nullptr)
                {
                    t->next() = head;
                    t->next()->prev() = t;
                }
                head = t;
                length += 1;
            }
        }

        const V& get(const K& key) const 
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            if(t != nullptr) {return t->data().value();}
            throw std::out_of_range("key not found");
        }

        V& get(const K& key) 
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            if(t == nullptr) 
            {
                t = new Node<Pair<K,V>>(Pair(key,V()));

                if(head != nullptr)
                {
                    t->next() = head;
                    t->next()->prev() = t;
                }
                head = t;
                length += 1;
            }
            return t->data().value();
        }

        void remove(const K& key)
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            if(t != nullptr)
            {
                if(t->prev() == nullptr) {head = t->next();}
                else {t->prev()->next() = t->next();}
                if(t->next() != nullptr) {t->next()->prev() = t->prev();}
                delete t;
                t = nullptr;
                length -= 1;
            }
        }

        bool contains(const K& key) const
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            return t != nullptr;
        }

        Iterator<Pair<K,V>> items() const {return Iterator(head);}
    };
}

#endif