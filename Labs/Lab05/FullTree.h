#ifndef FULLTREE_H
#define FULLTREE_H

#include <iostream>
#include <string>
#include "Queue.h"
#include "Tnode.h"

namespace dsl 
{
    template <typename T>
    void insert (Tnode<T>*& root, Queue<Tnode<T>*>& q, const T& obj)
    {
        if(root == nullptr && q.empty())
        {
            root = new Tnode<T>(obj);
            q.enqueue(root);
        }

        Tnode<T>* t = q.peek();
        if(t->left != nullptr && t->right != nullptr)
        {
            q.dequeue();
            q.enqueue(t->left());
            q.enqueue(t->right());
        }

        if(t->left() == nullptr)
        {
            t->left() = new Tnode<T>(obj);
        }

        else 
        {
            t->right() = new Tnode<T>(obj);
        }

    }


}

#endif
