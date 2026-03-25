#ifndef ITERABLE_H
#define ITERABLE_H

#include "Array.h"
#include "Object.h"
#include <stdexcept>

namespace dsn
{
	template <class T>
	class Iterator 
	{
		private:
		Array<T>* data;
		long size[2];

		public:
		Iterator() : data(nullptr), size{0,0} {}

		Iterator(Array<T>& obj,long d) : data(&obj), size{0,d} {}

		Iterator(const Iterator<T>& obj) 
		{
			data = obj.data;

			for(int i = 0;i < 2;i += 1) 
			{
				size[i] = obj.size[i];
			}
		}

		Iterator<T>& operator=(const Iterator<T>& rhs)
		{
			if(this != &rhs) 
			{
				data = rhs.data;

				for(int i = 0;i < 2;i += 1)
				{
					size[i] = rhs.size[i];
				}
			}
			return *this;
		}

		~Iterator() {data = nullptr;}

		void start() {size[0] = 0;}

		void end() {size[0] = size[1] - 1;}

		const T& current() const 
		{
			if(hasNext() && hasPrevious()) 
			{
				return (*data)[size[0]];
			}
			throw std::invalid_argument("node invalid");
		}

		T& current() 
		{
			if(hasNext() && hasPrevious()) 
			{
				return (*data)[size[0]];
			}
			throw std::invalid_argument("node invalid");
		}

		bool hasNext() const 
		{
			return data != nullptr && size[0] < size[1];
		}

		bool hasPrevious() const 
		{
			return data != nullptr && size[0] >= 0;
		}

		void forward() 
		{
			if(data != nullptr) {size[0] += 1;}
		}

		void backward() 
		{
			if(data != nullptr) {size[0] -= 1;}
		}
	};
}

#endif
