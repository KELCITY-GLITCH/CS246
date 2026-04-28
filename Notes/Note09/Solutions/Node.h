#ifndef NODE_H
#define NODE_H

namespace dsn 
{
	template <class T>
	class Node 
	{
		public:
		T data;
		Node<T>* prev;
		Node<T>* next;
		Node(const T& data) : Node(data,nullptr) {}
		Node(const T& data,Node<T>* next) : Node(data,nullptr,next) {}
		Node(const T& data,Node<T>* prev,Node<T>* next) : data(data), prev(prev), next(next) {}
	};
}

#endif
