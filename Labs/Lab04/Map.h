#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Array.h"
#include "Iterator.h"
#include "Pair.h"
#include "Object.h"

namespace dsl 
{
	template <class K,class V>
	class Map
	{
		private:
		Array<Pair<K,V>> data;
		size_t length;

		public:

		void put(const K&key, const V& value)
		{
			if(!contains(key))
			{
				if(length == data.size())
				{
					throw std::out_of_range("map is full");
				}
				data[length] = Pair<K,V>(key, value);
				length +=1;
			}
		}

		void remove(const K& key)
		{
			size_t t = 0;

			while(t < length && data[t].key() !=key)
			{
				t += 1;
			}

			if(t == length) { return; } //not found

			while(t+ 1 < length)
			{
				data[t] = data[t + 1];
				t += 1;
			}
			length -=1;
		}

		Map() : data(128), length(0) {}
		
		Map(size_t size) : data(size), length(0) {}

		Map(const Map<K,V>& obj) 
		{
			data = obj.data;
			length = obj.length;
		}

		Map<K,V>& operator=(const Map<K,V>& rhs)
		{
			if(this != &rhs)
			{
				data = rhs.data;
				length = rhs.length;
			}
			return *this;
		}

		~Map() {}

		V& get(const K& key)
		{
			size_t t = 0;

			while(t < length && data[t].key() != key)
			{
				t += 1;
			}

			if(t == length && length == data.size()) 
			{
				throw std::out_of_range("key not found");
			}
			else if(t == length) 
			{
				data[t] = Pair(key,V());
				length += 1;
			}
			return data[t].value();
		}

		const V& get(const K& key) const 
		{
			size_t t = 0;

			while(t < length && data[t].key() != key)
			{
				t += 1;
			}

			if(t < length) {return data[t].value();}
			throw std::out_of_range("key not found");
		}

		V& operator[](const K& key)
		{
			size_t t = 0;

			while(t < length && data[t].key() != key)
			{
				t += 1;
			}

			if(t == length && length == data.size()) 
			{
				throw std::out_of_range("key not found");
			}
			else if(t == length) 
			{
				data[t] = Pair(key,V());
				length += 1;
			}
			return data[t].value();
		}

		const V& operator[](const K& key) const 
		{
			size_t t = 0;

			while(t < length && data[t].key() != key)
			{
				t += 1;
			}

			if(t < length) {return data[t].value();}
			throw std::out_of_range("key not found");
		}

		bool contains(const K& key) const
		{
			size_t t = 0;

			while(t < length && data[t].key() != key)
			{
				t += 1;
			}
			return t != length;
		}

		bool empty() const {return length == 0;}

		bool full() const {return length == data.size();}

		size_t size() const {return length;}

		Iterator<Pair<K,V>> items() const 
		{
			return Iterator<Pair<K,V>>(data,length);
		}
	};
}

#endif
