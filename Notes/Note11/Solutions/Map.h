#ifndef MAP_H
#define MAP_H

#include "Pair.h"
#include "Node.h"
#include <stdexcept>

namespace dsn 
{
    template<class K,class V>
    class Map 
    {
        private:
        Node<Pair<K,V>> *head;
        size_t len;

        public:
        Map() : head(nullptr), len(0) {} 

        Map(const Map<K,V>& obj) 
        {
            head = clone(obj.head);
            len = obj.len;
        }

        Map<K,V>& operator=(const Map<K,V>& rhs)
        {
            if(this != &rhs)
            {
                destroy(head);
                head = clone(rhs.head);
                len = rhs.len;
            }
            return *this;
        }

        ~Map() {destroy(head);}

        void put(const K& key,const V& value)
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data.key != key)
            {
                t = t->next;
            }

            if(t == nullptr)
            {
                Pair<K,V> item(key,value);

                if(head == nullptr)
                {
                    head = new Node<Pair<K,V>>(item);
                }
                else 
                {
                    head->prev = new Node<Pair<K,V>>(item);
                    head->prev->next = head;
                    head = head->prev;
                }
                len += 1;
            }
        }

        void erase(const K& key)
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data.key != key)
            {
                t = t->next;
            }

            if(t != nullptr)
            {
                if(t->prev == nullptr)
                {
                    head = t->next;

                    if(head != nullptr)
                    {
                        head->prev = nullptr;
                    }
                }
                else 
                {
                    t->prev->next = t->next;
                }

                if(t->next != nullptr)
                {
                    t->next->prev = t->prev;
                }

                delete t;
                t = nullptr;
                len -= 1;
            }
        }

        V& get(const K& key) 
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data.key != key)
            {
                t = t->next;
            }

            if(t != nullptr)
            {
                return t->data.value;
            }
            else 
            {
                Pair<K,V> item(key,V());

                if(head == nullptr)
                {
                    head = new Node<Pair<K,V>>(item);
                }
                else 
                {
                    head->prev = new Node<Pair<K,V>>(item);
                    head->prev->next = head;
                    head = head->prev;
                }
                len += 1;
                return head->data.value;
            }
        }

        const V& get(const K& key) const  
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data.key != key)
            {
                t = t->next;
            }

            if(t != nullptr)
            {
                return t->data.value;
            }
            throw std::out_of_range("key not found");
        }

        bool contains(const K& key) const 
        {
            Node<Pair<K,V>>* t = head;

            while(t != nullptr && t->data.key != key)
            {
                t = t->next;
            }
            return t != nullptr;
        }

        bool empty() const {return head == nullptr;}

        size_t size() const {return len;}
    };
}

#endif