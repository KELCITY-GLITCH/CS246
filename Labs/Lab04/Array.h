#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <initializer_list>

namespace dsl
{
	template<class T>
	class Array
	{
		private:
		T* data;
		size_t capacity;

		std::string toString() const override 
		{
			std::ostringstream out;

			out << "[";

			for(size_t i = 0;i < capacity;i += 1)
			{
				out << data[i];
				if(i + 1 < capacity) {out << ",";}
			}
			out << "]";
			return out.str();
		}

		public:
		Array() : Array(20) {} 

		Array(size_t sz) : capacity(sz) 
		{
			if(capacity == 0) {capacity = 20;}
			data = new T[capacity];

			for(size_t i = 0;i < capacity;i += 1)
			{
				data[i] = T();
			}
		}

		Array(std::initializer_list<T> args)
		{
			capacity = args.size();
			if(capacity == 0) 
			{
				throw std::length_error("empty list");
			}
			data = new T[capacity];
			size_t i = 0;
			
			for(T x : args) 
			{
				data[i] = x;
				i += 1;
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

		~Array() {delete[] data;}

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

		size_t size() const {return capacity;}

		size_t length() const {return capacity;}
	};

}
#endif

//remove override at the end of the eader two string
//