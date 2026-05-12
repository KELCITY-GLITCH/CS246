#ifndef HEAP_H
#define HEAP_H

#include "Array.h"

namespace dsn
{
	size_t parent(size_t idx) {return (idx == 0)?(0):((idx - 1) / 2);}
	size_t left(size_t idx) {return 2 * idx + 1;}
	size_t right(size_t idx) {return 2 * idx + 2;}

	template <class T>
	class Heap : public Object
	{
		private: 
		Array<T> data;
		size_t heap_size;
		bool isHeap;

		T& operator[](size_t idx) 
		{
			if(idx < heap_size) {return data[idx];}
			throw std::out_of_range("empty heap");
		}

		public:
		Heap() : heap_size(0), data(30), isHeap(true) {}

		Heap(size_t size) : data(size), heap_size(0), isHeap(true) {}

		Heap(const Heap<T>& obj) 
		{
			data = obj.data;
			heap_size = obj.heap_size;
			isHeap = obj.isHeap;
		}

		Heap<T> operator=(const Heap<T>& rhs)
		{
			if(this != &rhs)
			{
				data = rhs.data;
				heap_size = rhs.heap_size;
				isHeap = rhs.isHeap;
			}
			return *this;
		}

		Heap(std::initializer_list<T> args)
		{
			heap_size = args.size();
			isHeap = true;

			if(heap_size == 0) 
			{
				throw std::length_error("empty list");
			}
			data = Array<T>(heap_size);
			size_t i = 0;
			
			for(T x : args) 
			{
				data[i] = x;
				i += 1;
			}
		}

		~Heap() {}

		const T& operator[](size_t idx) const 
		{
			if(idx < heap_size) {return data[idx];}
			throw std::out_of_range("empty heap");
		}

		void view(bool obj) {isHeap = obj;}

		size_t size() const {return heap_size;}

		size_t capacity() const {return data.size();}

		void set(size_t obj) 
		{
			if(obj < data.size()) {heap_size = obj;}
		}

		static void heapify(Heap<T>& obj,size_t idx)
		{
			size_t l = left(idx);
			size_t r = right(idx);
			size_t mx = idx;

			if(l < obj.heap_size && obj[l] > obj[mx])
			{
				mx = l;
			}

			if(r < obj.heap_size && obj[r] > obj[mx])
			{
				mx = r;
			}

			if(mx != idx)
			{
				T t = obj[idx];
				obj[idx] = obj[mx];
				obj[mx] = t;
				heapify(obj,mx);
			}
		}
		/*
		[7,6,9,8,2,4,1,5,3,0] = 10 
		idx = 0, l = 1, r = 2, mx = 2
		[9,6,7,8,2,4,1,5,3,0] = 10
		idx = 2, l = 5, r = 6, mx = 2
		*/

		void insert(const T& obj)
		{
			if(heap_size < data.size())
			{
				size_t p = parent(heap_size);
				size_t i = heap_size;
				
				while(i != p && obj > data[p])
				{
					data[i] = data[p];
					i = p;
					p = parent(i);
				}
				data[i] = obj;
				heap_size += 1;
			}
		}

		/*
		[] = 0
		obj = 7, p = 0, i = 0
		[7] = 1
		obj = 9, p = 0, i = 1 
		[7,7]
		i = 0, p = 0
		[9,7] = 2
		obj = 3, p = 0, i = 2
		[9,7,3] = 3
		obj = 6, p = 1, i = 3
		[9,7,3,6] = 4
		obj = 8, p = 1, i = 4
		[9,7,3,6,7]
		i = 1, p = 0
		[9,8,3,6,7]
		*/

		void remove(size_t idx)
		{
			if(idx < heap_size)
			{
				heap_size -= 1;
				T t = data[idx];
				data[idx] = data[heap_size];
				data[heap_size] = t;
				heapify(*this,idx);
			}
		}

		std::string toString() const override 
		{
			std::stringstream out;
			size_t n = data.size();

			if(isHeap) {n = heap_size;}

			out << "[";

			for(size_t i = 0;i < n;i += 1)
			{
				out << data[i];

				if(i + 1 < n) {out << ",";}
			}
			out << "]";
			return out.str();
		}
	};
}
#endif
