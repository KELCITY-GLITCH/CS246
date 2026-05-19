#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdexcept>
#include "Object.h"
#include "Queue.h"

namespace dsw
{
    template<class T>
    class PriorityQueue : public Object
    {
        private:
            Queue<T> table[5];
            unsigned int amount;
            unsigned int (*hash)(const T&);

            static unsigned int unit(const T& obj)
            {
                return 0;
            }

        public:
            PriorityQueue()
            {
                amount = 0;
                hash = unit;
            }

            PriorityQueue(unsigned int (*h)(const T&))
            {
                amount = 0;
                hash = h;
            }

            void enqueue(const T& obj)
            {
                unsigned int index = hash(obj) % 5;
                table[index].enqueue(obj);
                amount += 1;
            }

            void dequeue()
            {
                if(empty())
                {
                    throw std::out_of_range("empty priority queue");
                }

                for(unsigned int i = 0; i < 5; i += 1)
                {
                    if(!table[i].empty())
                    {
                        table[i].dequeue();
                        amount -= 1;
                        return;
                    }
                }
            }

            const T& peek() const
            {
                if(empty())
                {
                    throw std::out_of_range("empty priority queue");
                }

                for(unsigned int i = 0; i < 5; i += 1)
                {
                    if(!table[i].empty())
                    {
                        return table[i].peek();
                    }
                }

                throw std::out_of_range("empty priority queue");
            }

            bool empty() const
            {
                return amount == 0;
            }
    };
}

#endif