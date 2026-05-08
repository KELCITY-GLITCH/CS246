#ifndef BUILDGAME_H
#define BUILDGAME_H

#include <iostream>
#include <fstream>
#include <string>
#include "FullTree.h"
using namespace std;

namespace dsl 
{
    Tnode<string>* loadGame(ifstream& fin)
    {
        Tnode<string>* root = nullptr;
        Queue<Tnode<string>*> q;
        string line;

        if(fin.is_open())
        {
            while(getline(fin, line))
            {
                insert(root, q, line);
            }
        }
        return root;
    }

}

#endif
