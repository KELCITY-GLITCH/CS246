#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace dse
{
	class Object 
	{
		private:
		virtual std::string toString() const = 0;

		friend std::ostream& operator<<(std::ostream& out,const Object& obj)
		{
			return out << obj.toString();
		}
	};

	template <class T>
	class Array : public Object 
	{
		private:
		T* data;
		size_t capacity;

		public:
		Array() : Array(20) {}

		Array(size_t size) : capacity(size) 
		{
			if(capacity == 0) {capacity = 20;}
			data = new T[capacity];

			for(size_t i = 0;i < capacity;i += 1)
			{
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
				capacity = rhs.capacity;
				delete[] data;
				data = new T[capacity];

				for(size_t i = 0;i < capacity;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}
			return *this;
		}

		~Array() {delete[] data;}

		size_t size() const {return capacity;}

		const T& operator[](size_t idx) const 
		{
			if(idx < capacity) {return data[idx];}
			throw std::out_of_range("out of bound");
		}
		
		T& operator[](size_t idx) 
		{
			if(idx < capacity) {return data[idx];}
			throw std::out_of_range("out of bound");
		}

		std::string toString() const override 
		{
			std::stringstream out;
			
			out << "[";

			for(size_t i = 0;i < capacity;i += 1)
			{
				out << data[i];

				if(i + 1 < capacity) {out << ",";}
			}

			out << "]";
			return out.str();
		}
	};

	template <class T>
	class Node 
	{
		public:
		T data;
		Node<T>* prev;
		Node<T>* next;
		
		Node() : data(T()), prev(nullptr), next(nullptr) {}
		Node(const T& dt) : data(dt), prev(nullptr), next(nullptr) {}
	
		friend Node<T>* Clone(Node<T>* rt)
		{
			if(rt == nullptr)
			{
				return nullptr;
			}
			Node<T> * cp = new Node<T>(rt->data);
			Node<T> * tr = rt;
			Node<T> * tc = cp;

			while(tr->next != nullptr)
			{
				tc->next = new Node<T>(tr->next->data);
				tc->next->prev = tc;
				tc = tc->next;
				tr = tr->next;
			}
			return cp;
		}

		friend void Erase(Node<T>*& rt)
		{
			Node<T>* t;

			while(rt != nullptr)
			{
				t = rt;
				rt = rt->next;
				delete t;
				t = nullptr;
			}
		}

		friend Node<T>* Last(Node<T>* rt)
		{
			if(rt == nullptr) {return nullptr;}

			Node<T>* t = rt;
			while(t->next != nullptr) {t = t->next;}
			return t;
		}
	};

	template <class T>
	class Sequence : public Object 
	{
		public:
		virtual void insertFirst(const T&) = 0;
		virtual void insertLast(const T&) = 0;
		virtual void insertAfter(const T&,const T&) = 0;
		virtual void insertBefore(const T&,const T&) = 0;
		virtual void remove(const T&) = 0;
		virtual void removeFirst() = 0;
		virtual void removeLast() = 0;
		virtual void removeAfter(const T&) = 0;
		virtual void removeBefore(const T&) = 0;
		virtual bool contains() const = 0;
		virtual size_t size() const = 0;
	};		
}

#endif
