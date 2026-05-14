#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>

namespace dsw 
{
    template<class K,class V>
    class Pair 
    {
        public:
        K key;
        V value;

        Pair() 
        {
            key = K();
            value = V();
        }

        Pair(const K& key,const V& value) : key(key), value(value) {}
        
        Pair(const Pair<K,V>& obj) 
        {
            key = obj.key;
            value = obj.value;
        }

        Pair<K,V>& operator=(const Pair<K,V>& rhs)
        {
            if(this != &rhs)
            {
                key = rhs.key;
                value = rhs.value;
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& out,const Pair<K,V>& obj)
        {
            out << "(" << obj.key << "," << obj.value << ")";
            return out;
        } 
    };
}

#endif
