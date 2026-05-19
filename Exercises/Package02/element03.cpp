#include <iostream>
#include <string>
#include "Object.h"
#include "Queue.h"

using namespace std;
using namespace dsw;

void BC(size_t n)
{
    if(n == 0)
    {
        return;
    }

    Queue<string> q;

    q.enqueue("1");

    for(size_t i = 1; i <= n; i += 1)
    {
        string current = q.peek();
        q.dequeue();

        cout << current << endl;

        q.enqueue(current + "0");
        q.enqueue(current + "1");
    }
}

int main()
{
    BC(7);

    return 0;
}