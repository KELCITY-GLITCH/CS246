#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Node.h"

namespace dsn 
{
    template <class T> class List;
    template <class T> class Iterator;

    template <class T>
    class List
    {
        private:
        Node<T>* head;
        Node<T>* tail;
        size_t length;
        friend class Iterator<T>;

        public:

        List() : head(nullptr), tail(nullptr), length(0) {}

        List(const List<T>& obj)
        {
            head = clone(obj.head);
            tail = head;
            length = obj.length;

            if(head != nullptr)
            {
                while(tail->next() != nullptr) {tail = tail->next();}
            }
        }

        List<T>& operator=(const List<T>& rhs)
        {
            if(this != &rhs)
            {
                clear(head);
                head = clone(rhs.head);
                tail = head;
                length = rhs.length;

                if(head != nullptr)
                {
                    while(tail->next() != nullptr) {tail = tail->next();}
                }
            }
            return *this;
        }

        ~List() 
        {
            clear(head);
            head = nullptr;
            tail = nullptr;
        }

        void prepend(const T& obj)
        {
            //O(1) - simply assignmnts and selection statements
            Node<T>* t = new Node<T>(obj);

            if(head == nullptr)
            {
                head = t;
                tail = t;
            }
            else 
            {
                t->next() = head;
                head->prev() = t;
                head = t;
            }
	    length += 1;
        }

        void append(const T& obj)
        {
            //O(1)
            Node<T>* t = new Node<T>(obj);

            if(head == nullptr)
            {
                head = t;
                tail = t;
            }
            else 
            {
                t->prev() = tail;
                tail->next() = t;
                tail = t;
            }
	    length += 1;
        }

        void insert(size_t idx,const T& obj)
        {
            //O(n)
            Node<T>* p = nullptr;

            if(idx <= (length / 2))
            {
                p = head;
                for(size_t i = 0;i < idx;i += 1)
                {
                    p = p->next();
                }
            }
            else if(idx > (length / 2) && idx <= length)
            {
                p = tail;
                for(size_t i = length-idx;i > 0;i -= 1)
                {
                    p = p->prev();
                }
            }

            if((p == nullptr && idx == 0) || p != nullptr)
            {
                Node<T>* t = new Node<T>(obj);

                if(p == nullptr)
                {
                    head = t;
                    tail = t;
                }
                else 
                {
                    t->prev() = p->prev();
                    t->next() = p;                

                    if(t->prev() == nullptr) {head = t;}
                    else {t->prev()->next() = t;}
                    t->next()->prev() = t;
                }
		length += 1;
            }
        }

	void insertAfter(Iterator<T>& itr,const T& obj)
	{
		if(itr.self == this && itr.node != nullptr)
		{
			//O(1)
			Node<T>* t = new Node<T>(obj);

			t->next() = itr.node->next();
			t->prev() = itr.node;

			if(t->next() == nullptr) {tail = t;}
			else {t->next()->prev() = t;}
			t->prev()->next() = t;
			length += 1;
		}	
	}

	void insertBefore(Iterator<T>& itr,const T& obj)
	{
		if(itr.self != this && itr.node != nullptr)
		{
			//O(1)
			Node<T>* t = new Node<T>(obj);

			t->prev() = itr.node->prev();
			t->next() = itr.node;

			if(t->prev() == nullptr) {head = t;}
			else {t->prev()->next() = t;}
			t->next()->prev() = t;
			length += 1;
		}
	}

	void removeFirst() 
	{
		//O(1)
		if(head != nullptr)
		{
			Node<T>* t = head;
			head = head->next();

			if(head == nullptr) {tail = nullptr;}
			else {head->prev() = nullptr;}
			delete t;
			length -= 1;
		}
	}

	void removeLast() 
	{
		//O(1)
		if(head != nullptr)
		{
			Node<T>* t = tail;
			tail = tail->prev();

			if(tail == nullptr) {head = nullptr;}
			else {tail->next() = nullptr;}
			delete t;
			length -= 1;
		}
	}

	void remove(size_t idx)
	{
		Node<T>* p = nullptr;
		size_t i;

		if(idx <= (length/2)) 
		{
			p = head;
			i = 0;
		
			while(i < idx) 
			{
				p = p->next();
				i += 1;
			}
		}
		else if(idx > (length / 2) && idx <= length)
		{
			p = tail;
			i = length;

			while(i > idx) 
			{
				p = p->prev();
				i -= 1;
			}
		}

		if(p != nullptr)
		{
			if(p->next() == nullptr) {tail = p->prev();} 
			else {p->next()->prev() = p->prev();}
			
			if(p->prev() == nullptr) {head = p->next();}
			else {p->prev()->next() = p->next();}
			delete p;
			length -= 1;
		}
	}

	void erase(Iterator<T>& itr) 
	{
		//O(1)
		if(itr.self == this && itr.node != nullptr)
		{
			Node<T>* p = itr.node;

			if(p->next() == nullptr) {tail = p->prev();}
			else {p->next()->prev() = p->prev();}

			if(p->prev() == nullptr) {head = p->next();}
			else {p->prev()->next() = p->next();}
			delete p;
			length -= 1;
		}
	}

	void erase()
	{
		//O(n)
		clear(head);
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	bool contains(const T& obj) const 
	{
		//O(n)
		Node<T>* t = head;

		while(t != nullptr && t->data() != obj) {t = t->next();}
		return t != nullptr;
	}

	size_t search(const T& obj) 
	{
		//O(n)
		Node<T>* t = head;
		size_t i = 0;

		while(t != nullptr && t->data() != obj) 
		{
			t = t->next();
			i += 1;
		}
		return i;
	}

	Iterator<T> find(const T& obj)
	{
		//O(n)
		Node<T>* t = head;

		while(t != nullptr && t->data() != obj) {t = t->next();}
		return Iterator<T>(*this,t);
	}

	T& get(size_t idx) 
	{
		//O(n)
		Node<T>* t = head;
		size_t i = 0;

		while(t != nullptr && i < idx) 
		{
			t = t->next();
			i += 1;
		}

		if(t != nullptr) {return t->data();}
		throw std::invalid_argument("invalid index");
	}

	const T& get(size_t idx) const 
	{
		//O(n)
		Node<T>* t = head;
		size_t i = 0;

		while(t != nullptr && i < idx) 
		{
			t = t->next();
			i += 1;
		}

		if(t != nullptr) {return t->data();}
		throw std::invalid_argument("invalid index");
	}

	T& first() 
	{
		//O(1)
		if(head != nullptr) {return head->data();}
		throw std::invalid_argument("list is empty");
	}

	const T& first() const 
	{
		//O(1)
		if(head != nullptr) {return head->data();}
		throw std::invalid_argument("list is empty");
	}

	T& last() 
	{
		//O(1)
		if(tail != nullptr) {return tail->data();}
		throw std::invalid_argument("list is empty");
	}

	const T& last() const  
	{
		//O(1)
		if(tail != nullptr) {return tail->data();}
		throw std::invalid_argument("list is empty");
	}

	bool empty() const {return head == nullptr;}

	size_t size() const {return length;}
    };

    template <class T>
    class Iterator 
    {
        private:
        List<T>* self;
        Node<T>* node;
        friend class List<T>;

        Iterator(List<T>* l,Node<T>* n) : self(l), node(n) {}

        public:
        Iterator() : self(nullptr), node(nullptr) {}

        Iterator(List<T>& s) : self(&s), node(nullptr) {}

        Iterator(const Iterator<T>& obj) {self = obj.self;}

        Iterator<T>& operator=(const Iterator<T>& rhs)
        {
            if(this != &rhs)
            {
                self = rhs.self;
            }
            return *this;
        }

        ~Iterator() 
        {
            self = nullptr;
            node = nullptr;
        }

        void begin() 
        {
            if(self != nullptr) {node = self->head;}
            else {node = nullptr;}
        }

        void end() 
        {
            if(self != nullptr) {node = self->tail;}
            else {node = nullptr;}
        }

        const T& current() const 
        {
            if(node != nullptr) {return node->data();}
            throw std::invalid_argument("iterator not positioned");
        }

        T& current() 
        {
            if(node != nullptr) {return node->data();}
            throw std::invalid_argument("iterator not positioned");
        }

        bool hasNext() const {return (node != nullptr && node->next() != nullptr);}

        bool hasPrevious() const {return (node != nullptr && node->prev() != nullptr);}

        void forward() {if(node != nullptr) {node = node->next();}}

        void backward() {if(node != nullptr) {node = node->prev();}}
    };

}

#endif
