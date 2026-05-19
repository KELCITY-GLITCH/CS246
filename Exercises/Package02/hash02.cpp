#include <iostream>
#include <string>
#include "Object.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;
using namespace dsw;

struct Task
{
    string name;
    unsigned int priority;
};

ostream& operator<<(ostream& out, const Task& task)
{
    out << task.name << " - Priority " << task.priority;
    return out;
}

unsigned int taskHash(const Task& task)
{
    return task.priority;
}

int main()
{
    PriorityQueue<Task> scheduler(taskHash);

    Task t1 = {"Study for exam", 0};
    Task t2 = {"Do laundry", 3};
    Task t3 = {"Finish homework", 1};
    Task t4 = {"Play game", 4};
    Task t5 = {"Email professor", 2};

    scheduler.enqueue(t1);
    scheduler.enqueue(t2);
    scheduler.enqueue(t3);
    scheduler.enqueue(t4);
    scheduler.enqueue(t5);

    cout << "Task Scheduler" << endl;

    while(!scheduler.empty())
    {
        cout << scheduler.peek() << endl;
        scheduler.dequeue();
    }

    return 0;
}=