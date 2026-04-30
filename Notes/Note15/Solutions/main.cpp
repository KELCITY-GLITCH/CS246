#include <iostream>
#include <string>
#include "TreeNode.h"

template <typename T>
void display(const T& value)
{
    std::cout << value << " ";
}

void doubles(int& value)
{
    value *= 2;
}

int main()
{
    dsn::Tnode<int>* rt = new dsn::Tnode<int>(10);
    rt->left() = new dsn::Tnode<int>(9);
    rt->left()->left() = new dsn::Tnode<int>(6);
    rt->left()->right() = new dsn::Tnode<int>(4);
    rt->right() = new dsn::Tnode<int>(8);
    rt->right()->left() = new dsn::Tnode<int>(2);
    rt->right()->right() = new dsn::Tnode<int>(1);

    dsn::Tnode<int>* cp = dsn::clone(rt,rt->p());

    dsn::infix(rt,display<int>);
    std::cout << "\n";
    dsn::prefix(rt,display<int>);
    std::cout << "\n";
    dsn::postfix(rt,display<int>);
    std::cout << "\n";

    dsn::infix(cp,doubles);

    dsn::infix(cp,display<int>);
    std::cout << "\n";
    dsn::prefix(cp,display<int>);
    std::cout << "\n";
    dsn::postfix(cp,display<int>);
    std::cout << "\n";

    dsn::erase(rt);
    dsn::erase(cp);
    
    return 0;
}