#ifndef SET_H
#define SET_H

#include "Map.h"

namespace dsn 
{
    template<class T>
    class Set 
    {
        private:
        Map<T,T> data;

        public:
        Set() {} 

        Set(const Set<T>& obj) {data = obj.data;}

        Set<T>& operator=(const Set<T>& rhs)
        {
            if(this != &rhs)
            {
                data = rhs.data;
            }
            return *this;
        }

        ~Set() {}

        void add(const T& item) {data.put(item,item);}

        void erase(const T& item) {data.erase(item);} 

        bool contains(const T& item) const 
        {
            return data.contains(item);
        } 
        
        bool empty() const {return data.empty();}

        size_t size() const {return data.size();}
    };
}

#endif