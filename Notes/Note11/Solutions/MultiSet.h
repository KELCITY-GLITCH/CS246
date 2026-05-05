#ifndef MULTISET_H
#define MULTISET_H

#include "Map.h"

namespace dsn 
{
    template<class T>
    class MultiSet 
    {
        private:
        Map<T,size_t> data;

        public:
        MultiSet() {} 

        MultiSet(const MultiSet<T>& obj) {data = obj.data;}

        MultiSet<T>& operator=(const MultiSet<T>& rhs)
        {
            if(this != &rhs)
            {
                data = rhs.data;
            }
            return *this;
        }

        ~MultiSet() {}

        void add(const T& item) 
        {
            data.get(item) = data.get(item) + 1;
        }

        void erase(const T& item) 
        {
            if(data.contains(item))
            {
                if(data.get(item) == 1)
                {
                    data.erase(item);
                }
                else 
                {
                    data.get(item) -= 1;
                }
            }
        } 

        bool contains(const T& item) const 
        {
            return data.contains(item);
        } 
        
        bool empty() const {return data.empty();}

        size_t size() const {return data.size();}

        size_t count(const T& item) const 
        {
            if(data.contains(item)) {return data.get(item);}
            return 0;
        }

        void removeAll(const T& item) {data.erase(item);}
    };
}

#endif