#ifndef HEAP_H
#define HEAP_H

#include "Array.h"

namespace dsn
{
	template <class T>
	class Heap
	{
		private: 
		Array<T> data;
		size_t heap_size;

		public:
		Heap() : heap_size(0), data(30) {}

		Heap(size_t size) : data(size), heap_size(0) {}

		Heap(const Heap<T>& obj) 
		{
			data = obj.data;
			heap_size = obj.heap_size;
		}

		Heap<T> operator=(const Heap<T>& rhs)
		{
			if(this != &rhs)
			{
				data = rhs.data;
				heap_size = rhs.heap_size;
			}
			return *this;
		}

		~Heap() {}


	};
}
#endif
