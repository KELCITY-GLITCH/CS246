#include "Tools.h"

template <typename T>
void Print(dse::Node<T>* rt)
{
	std::cout << "[";

	for(dse::Node<T>* t = rt;t != nullptr;t = t->next)
	{
		std::cout << t->data;

		if(t->next != nullptr) {std::cout << ",";}
	}

	std::cout << "]";
}

int main() 
{
	dse::Node<int>* t = new dse::Node<int>(2);
	dse::Node<int>* p = t;
	dse::Array<int> a(11);
	a[0] = 2;

	for(int i = 1;i <= 10;i += 1)
	{
		a[i] = (2 * (i + 1));
		p->next = new dse::Node<int>(2 * (i + 1));
		p->next->prev = p;
		p = p->next;

	}

	Print(t);
	std::cout << "\n" << a << "\n";
	Erase(t);
	return 0;
}
