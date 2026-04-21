#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <string>
#include <sstream>
#include "Pair.h"
#include "Node.h"
#include "Iterator.h"

namespace dsn 
{
    template <class K,class V>
    class HashMap
    {
        private:
        size_t single(const K& obj) {return 0;}
        Node<Pair<K,V>>* data[101];
        size_t (*hash)(const K& obj);
        size_t length;

        public:
        HashMap() 
        {
            length = 0;
            hash = single;

            for(int i = 0;i < 101;i += 1)
            {
                data[i] = nullptr;
            }
        }

        HashMap(size_t (*h)(const K&))
        {
            hash = h;
            length = 0;

            for(int i = 0;i < 101;i += 1)
            {
                data[i] = nullptr;
            }
        }

        HashMap(const HashMap<K,V>& obj)
        {
            hash = obj.hash;
            length = obj.length;

            for(int i = 0;i < 101;i += 1)
            {
                data[i] = clone(obj.data[i]);
            }
        }

        HashMap<K,V> operator=(const HashMap<K,V>& rhs)
        {
            if(this != &rhs)
            {
                hash = rhs.hash;
                length = rhs.length;

                for(int i = 0;i < 101;i += 1)
                {
                    clear(data[i]);
                    data[i] = clone(rhs.data[i]);
                }
            }
            return *this;
        }

        ~HashMap()
        {
            for(int i = 0;i < 101;i += 1)
            {
                clear(data[i]);
                data[i] = nullptr;
            }
        }

        bool empty() const {return length == 0;}

        size_t size() const {return length;}

        void put(const K& key,const V& value)
        {
            size_t idx = hash(key) % 101;
            Node<Pair<K,V>>* t = data[idx];

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            if(t == nullptr)
            {
                t = new Node<Pair<K,V>>(Pair(key,value));

                if(data[idx] != nullptr)
                {
                    t->next() = data[idx];
                    t->next()->prev() = t;
                }
                data[idx] = t;
                length += 1;
            }
        }

        const V& get(const K& key) const 
        {
            size_t idx = hash(key) % 101;
            Node<Pair<K,V>>* t = data[idx];

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            if(t != nullptr) {return t->data().value();}
            throw std::out_of_range("key not found");
        }

        V& get(const K& key) 
        {
            size_t idx = hash(key) % 101;
            Node<Pair<K,V>>* t = data[idx];

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            if(t == nullptr) 
            {
                t = new Node<Pair<K,V>>(Pair(key,V()));

                if(data[idx] != nullptr)
                {
                    t->next() = data[idx];
                    t->next()->prev() = t;
                }
                data[idx] = t;
                length += 1;
            }
            return t->data().value();
        }

        void remove(const K& key)
        {
            size_t idx = hash(key) % 101;
            Node<Pair<K,V>>* t = data[idx];

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            if(t != nullptr)
            {
                if(t->prev() == nullptr) {data[idx] = t->next();}
                else {t->prev()->next() = t->next();}
                if(t->next() != nullptr) {t->next()->prev() = t->prev();}
                delete t;
                t = nullptr;
                length -= 1;
            }
        }

        bool contains(const K& key) const
        {
            size_t idx = hash(key) % 101;
            Node<Pair<K,V>>* t = data[idx];

            while(t != nullptr && t->data().key() != key)
            {
                t = t->next();
            }

            return t != nullptr;
        }

        Iterator<Pair<K,V>> items() const 
        {
            Node<Pair<K,V>>* head = nullptr, *t;

            for(int i = 0;i < 101;i += 1)
            {
                if(data[i] != nullptr)
                {
                    if(head == nullptr)
                    {
                        head = clone(data[i]);
                        t = head;
                    }
                    else 
                    {
                        t->next() = clone(data[i]);
                    }

                    while(t->next() != nullptr)
                    {
                        t = t->next();
                    }
                }
            }
            return Iterator(head);
        }
    };
}

#endif