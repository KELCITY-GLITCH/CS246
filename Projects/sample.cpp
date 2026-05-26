#include <iostream>
#include <string>
#include <sstream>
#include "Point.h"
#include "Grid.h"
#include "Deque.h"

using namespace std;
using namespace dsp;

struct Step
{
    Point p;
    string path;
};

char direction(const Point& from, const Point& to)
{
    if(to == from.left())
    {
        return 'l';
    }
    else if(to == from.right())
    {
        return 'r';
    }
    else if(to == from.up())
    {
        return 'u';
    }
    else if(to == from.down())
    {
        return 'd';
    }

    return ' ';
}

void adjacents(const Point& p, const Grid& g, Deque<Point>& s)
{
    Point q;

    q = p.right();
    if(q != p && g.available(q))
    {
        s.insertFirst(q);
    }

    q = p.down();
    if(q != p && g.available(q))
    {
        s.insertFirst(q);
    }

    q = p.left();
    if(q != p && g.available(q))
    {
        s.insertFirst(q);
    }

    q = p.up();
    if(q != p && g.available(q))
    {
        s.insertFirst(q);
    }
}

string pathfinder(Grid& g)
{
    Deque<Step> stack;

    Step start;
    start.p = g.start();
    start.path = "";

    stack.insertFirst(start);

    while(!stack.empty())
    {
        Step current = stack.first();
        stack.removeFirst();

        if(current.p == g.end())
        {
            return current.path;
        }

        if(g.available(current.p) || current.p == g.start())
        {
            g.mark(current.p);

            Deque<Point> neighbors;
            adjacents(current.p, g, neighbors);

            while(!neighbors.empty())
            {
                Point next = neighbors.first();
                neighbors.removeFirst();

                Step step;
                step.p = next;
                step.path = current.path + direction(current.p, next);

                stack.insertFirst(step);
            }
        }
    }

    return "";
}

int main()
{
    cout << "Test Case 1 - Straight Path" << endl;

    Grid g1(2, 5);
    g1.load("0000011110");

    Point p1(2, 5);

    p1.set(0, 0);
    g1.start(p1);

    p1.set(1, 4);
    g1.end(p1);

    Grid copy1 = g1;
    string path1 = pathfinder(copy1);

    cout << "Path: " << path1 << endl;
    cout << "Valid Path: " << g1.path(path1) << endl;
    cout << g1 << endl;


    cout << "Test Case 2 - Verification" << endl;

    Grid g2(5, 5);
    g2.load("0001110100101000001011000");

    Point p2(5, 5);

    p2.set(0, 0);
    g2.start(p2);

    p2.set(1, 3);
    g2.end(p2);

    Grid copy2 = g2;
    string path2 = pathfinder(copy2);

    cout << "Path: " << path2 << endl;
    cout << "Valid Path: " << g2.path(path2) << endl;
    cout << g2 << endl;


    cout << "Test Case 3 - No Path" << endl;

    Grid g3(3, 3);
    g3.load("011010111");

    Point p3(3, 3);

    p3.set(0, 0);
    g3.start(p3);

    p3.set(1, 2);
    g3.end(p3);

    Grid copy3 = g3;
    string path3 = pathfinder(copy3);

    cout << "Path: " << path3 << endl;
    cout << "Valid Path: " << g3.path(path3) << endl;
    cout << g3 << endl;

    return 0;
}