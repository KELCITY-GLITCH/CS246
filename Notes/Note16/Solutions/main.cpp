#include <iostream>
#include "Heap.h"

template <typename T>
void BuildHeap(dsn::Heap<T>& obj)
{
    obj.set(obj.capacity());
    size_t i = obj.size() / 2;

    while(true)
    {
        dsn::Heap<T>::heapify(obj,i);
        if(i == 0) {break;}
        else {i -= 1;}
    }
}

template <typename T>
void HeapSort(dsn::Heap<T>& obj)
{
    BuildHeap(obj);
    while(obj.size() > 0)
    {
        obj.remove(0);
    }
}

int main()
{
    dsn::Array<int> B = {11,1,6,3,4,7,9,2,5,12,16,17,20};
    dsn::Heap<int> A = {11,1,6,3,4,7,9,2,5,12,16,17,20};
    dsn::Heap<int> C(B.size());

    for(int i = 0;i < B.size();i += 1)
    {
        C.insert(B[i]);
    }

    std::cout << A << "\n";
    std::cout << C << "\n";

    std::cout << "\n";

    HeapSort(A);
    HeapSort(C);
    A.view(false);
    C.view(false);
    std::cout << A << "\n";
    std::cout << C << "\n";
    return 0;

    /*
    Priority Queue
    Enqueue(obj) = heap.insert(obj);
    Dequeue() = heap.remove(0);
    Peek() = heap[0];
    Empty() = heap.size() == 0; 
    */
}