#ifndef TREENODE_H
#define TREENODE_H

namespace dsn
{
    template <class T>
    class Tnode
    {
        private:
        T value;
        Tnode<T>* links[3];

        public:
        Tnode() : value(T()), links{nullptr,nullptr,nullptr} {}
        
        Tnode(const T& data) : value(data), links{nullptr,nullptr,nullptr} {}

        ~Tnode() {}

        Tnode(const Tnode<T>& obj) : Tnode(obj.value) {}

        Tnode<T>& operator=(const Tnode<T>& rhs)
        {
            if(this != &rhs)
            {
                value = rhs.value;
            }
            return *this;
        }

        T& data() {return value;}
        const T& data() const {return value;}

        Tnode<T>*& p() {return links[0];}
        const Tnode<T>*& p() const {return links[0];}
    
        Tnode<T>*& left() {return links[1];}
        const Tnode<T>*& left() const {return links[1];}
    
        Tnode<T>*& right() {return links[2];}
        const Tnode<T>*& right() const {return links[2];}
    };

    template <typename T>
    Tnode<T>* clone(Tnode<T>* rt,Tnode<T>* p)
    {
        if(rt == nullptr) {return nullptr;}
        Tnode<T>* t = new Tnode(rt->data());
        t->p() = p;
        t->left() = clone(rt->left(),t);
        t->right() = clone(rt->right(),t);
        return t;
    }

    template <typename T>
    void erase(Tnode<T>*& rt)
    {
        if(rt != nullptr)
        {
            erase(rt->left());
            erase(rt->right());
            delete rt;
            rt = nullptr;
        }
    }

    template <typename T, typename F>
    void infix(Tnode<T>* rt,F func)
    {
        if(rt != nullptr)
        {
            infix(rt->left(),func);
            func(rt->data());
            infix(rt->right(),func);
        }
    }

    template <typename T, typename F>
    void prefix(Tnode<T>* rt,F func)
    {
        if(rt != nullptr)
        {
            func(rt->data());
            prefix(rt->left(),func);
            prefix(rt->right(),func);
        }
    }

    template <typename T, typename F>
    void postfix(Tnode<T>* rt,F func)
    {
        if(rt != nullptr)
        {
            postfix(rt->left(),func);
            postfix(rt->right(),func);
            func(rt->data());
        }
    }

}

#endif