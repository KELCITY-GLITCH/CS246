#ifndef ARRAYLIST_H
#define ARRAYLIST_H 

#include <iostream>
#include <string> 
#include "Array.h"
#include "Object.h"

namespace dsn 
{
    template <class T>
    class ArrayList 
    {
        private:
        Array<T> data;
        size_t size;

        public:
        ArrayList() : size(0), data(100) {}

        ArrayList (unsigned int capacity) : size(0), data(capacity) {}

        ArrayList(const ArrayList<T>& obj) 
        {
            size = obj.size;
            data = obj.data;
        }

        ArrayList<T>& operator=(const ArrayList<T>& rhs) 
        {
            if(this != &rhs)
            {
                size = rhs.size;
                data = rhs.data;
            }
            return *this;
        }

        ~ArrayList() {}

        void append(const T& obj)
        {
            //O(1) because directly at the end which requires no shifting
            if(size < data.size())
            {
                data[size] = obj;
                size += 1;
            }
        }

        void insert(size_t idx,const T& obj)
        {
            //O(n) because it needs to shift elements
            //size does not exceed array capacity and 
            //the index is valid
            if(idx <= size && size < data.size())
            {
                //shift elements
                for(size_t i = size;i > idx;i -= 1)
                {
                    data[i] = data[i-1];
                }
                data[idx] = obj;
                size += 1;
            }
        }

        void remove(size_t idx) 
        {
            if(idx < size && size > 0)
            {
                size -= 1;

                for(size_t i = idx;i < size;i += 1)
                {
                    data[i] = data[i+1];
                }
            }
        }

        void detach() 
        {
            if(size > 0) {size -= 1;}
        }

        size_t find(const T& obj) const
        {
            //O(n) because you need to traverse the dataset
            size_t i = 0;

            while(i < size && data[i] != obj) {i += 1;}
            return i;
        }

        bool contains(const T& obj) const
        {
            //O(n) because you need to traverse the dataset
            size_t i = 0;

            while(i < size && data[i] != obj) {i += 1;}
            return i != size;
        }

        const T& at(size_t idx) const 
        {
            if(idx < size) {return data[idx];}
            throw std::out_of_range("invalid index");
        }

        const T& operator[](size_t idx) const 
        {
            if(idx < size) {return data[idx];}
            throw std::out_of_range("invalid index");
        }

        bool empty() const {return size == 0;}

        size_t length() const {return size;}

        bool full() const {return size == data.size(); }
    };
}

#endif
