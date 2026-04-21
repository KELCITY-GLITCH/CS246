#ifndef ITERABLE_H
#define ITERABLE_H

#include "Node.h"
#include <stdexcept>

namespace dsn
{
	template <class T>
	class Iterator 
	{
		private:
		Node<T>* node[2];

		public:
		Iterator() : node{nullptr,nullptr} {}

		Iterator(Node<T>* obj) : node{obj,nullptr} {}

		Iterator(const Iterator<T>& obj) 
		{
			node[0] = obj.node[0];
			node[1] = nullptr;
		}

		Iterator<T>& operator=(const Iterator<T>& rhs)
		{
			if(this != &rhs) 
			{
				node[0] = rhs.node[0];
				node[1] = nullptr;
			}
			return *this;
		}

		~Iterator() 
		{
			node[0] = nullptr;
			node[1] = nullptr;
		}

		void start() 
		{
			if(node[0] != nullptr) 
			{
				node[1] = node[0];

				while(node[1]->prev() != nullptr) 
				{
					node[1] = node[1]->prev();
				}
			}
		}

		void end() 
		{
			if(node[0] != nullptr)
			{
				node[1] = node[0];

				while(node[1]->next() != nullptr)
				{
					node[1] = node[1]->next();
				}
			}
		}

		const T& current() const 
		{
			if(node[1] != nullptr) {return node[1]->data();}
			throw std::invalid_argument("node invalid");
		}

		T& current() 
		{
			if(node[1] != nullptr) {return node[1]->data();}
			throw std::invalid_argument("node invalid");
		}

		bool hasNext() const 
		{
			return node[1] != nullptr;
		}

		bool hasPrevious() const 
		{
			return node[1] != nullptr;
		}

		void forward() 
		{
			if(node[1] != nullptr) 
			{
				node[1] = node[1]->next();
			}
		}

		void backward() 
		{
			if(node[1] != nullptr) 
			{
				node[1] = node[1]->prev();
			}
		}
	};
}

#endif
