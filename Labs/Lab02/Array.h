#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream> 
#include <stdexcept> 
#include "Object.h" 

namespace dsn 
{
    template <class T> 
    class Array : public Object 
    {
        private:
        T* data;
        size_t capacity;

        public:
        Array() : capacity(10)
        {
            data = new T[capacity];
            for (size_t i = 0; i < capacity; ++i) {
                data[i] = T(); 
            }
        }

        Array(size_t sz) : capacity(sz)
        {
            if (capacity == 0) { capacity = 10; }
            data = new T[capacity];
            for (size_t i = 0; i < capacity; ++i) {
                data[i] = T(); 
            }
        }

        Array(const Array<T>& obj)
        {
            capacity = obj.capacity;
            data = new T[capacity];

            for(size_t i = 0;i < capacity;i += 1)
            {
                data[i] = obj.data[i];
            }

        }

        Array<T>& operator=(const Array<T>& rhs)
        {
            if(this != &rhs)
            {
                delete[] data;
                capacity = rhs.capacity;
                data = new T[capacity];

                for(size_t i = 0;i < capacity;i += 1)
                {
                    data[i] = rhs.data[i];
                }
            }
            return *this;
        }

        virtual ~Array() {delete[] data;}

        size_t size() const {return capacity;}

        size_t length() const {return capacity;}

        const T& operator[](size_t idx) const 
        {
            if(idx < capacity) {return data[idx];}
            throw std::out_of_range("invalid index");
        }  
    
        T& operator[](size_t idx) 
        {
            if(idx < capacity) {return data[idx];}
            throw std::out_of_range("invalid index");
        }  
        
        std::string toString() const override
        {
            std::ostringstream out;
            out << '[';
            for (size_t i = 0; i < capacity; ++i) {
                if (i) out << ", ";
                out << data[i];
            }
            out << ']';
            return out.str();
        }


    };
}
#endif